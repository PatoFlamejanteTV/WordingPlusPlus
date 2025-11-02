# Modernization Report

This report analyzes the legacy WordPad codebase and provides a set of modernization targets. The analysis is based on a review of the C++ source files, including `wordpad.cpp`, `wordpad.h`, `wordpdoc.h`, and `wordpvw.h`.

## 1. Outdated Language Features

The codebase extensively uses C++ features and patterns from the 1990s, which have been superseded by safer, more modern alternatives.

-   **Manual Memory Management**: The code frequently relies on manual allocation and deallocation of memory using `new` and `delete`. This is error-prone and can lead to memory leaks.
    -   *Example*: In `wordpad.cpp`, the `CWordPadApp::PrintTwips` function allocates memory with `pVal = new int[nDec+1]` and later frees it with `delete []pVal;`.

-   **Raw Pointers**: Raw pointers are used pervasively for object ownership and manipulation, increasing the risk of memory leaks and dangling pointers.

-   **C-Style Strings**: The code uses C-style string manipulation functions (`_stprintf`, `lstrcat`, `lstrcmpA`) and character types (`TCHAR`, `LPTSTR`). These are not type-safe and are a common source of buffer overflows.
    -   *Example*: In `wordpad.cpp`, `PrintTwips` uses `_stprintf` and `lstrcat` to format a string, which is unsafe.

-   **Non-RAII Code**: Resources like device contexts (`CDC`) or memory are managed manually. The Resource Acquisition Is Initialization (RAII) pattern is not used, making resource management fragile.
    -   *Example*: In the `CWordPadApp` destructor in `wordpad.cpp`, the screen device context is manually released: `::ReleaseDC(NULL, m_dcScreen.Detach());`.

## 2. Obsolete Windows APIs

The application is built directly on top of legacy Windows APIs, many of which are obsolete or have modern wrappers that provide better safety and abstraction.

-   **GDI**: The codebase uses the Graphics Device Interface (e.g., `CDC` in `wordpad.h`) for rendering. Modern applications typically use hardware-accelerated graphics APIs like Direct2D or libraries that abstract platform-specific rendering.

-   **COM**: The Component Object Model is used for OLE embedding (e.g., `COleTemplateServer` in `wordpad.cpp`). While COM is complex, it remains the underlying technology for OLE on Windows. The modernization plan must include a strategy for this feature, such as creating modern C++ wrappers around the necessary COM interfaces to isolate legacy code, or evaluating alternative modern technologies for object embedding if maintaining OLE compatibility is not a requirement.

-   **Low-Level Win32 API**: Direct use of low-level Windows APIs (e.g., `HWND`, `RegisterWindowMessage`, `GetVersion`) makes the code non-portable and tightly coupled to the Windows platform.

## 3. Architecture Issues

The application follows the classic MFC Document/View architecture, which leads to several design problems.

-   **Tight Coupling**: The `CWordPadDoc` (document), `CWordPadView` (view), and `CMainFrame` (UI frame) classes are tightly interconnected. The document class, for instance, has knowledge of the view, and the application class (`CWordPadApp`) acts as a central hub holding global state.

-   **Lack of Modularity**: The codebase is monolithic, with most of the logic contained within a single executable. There is little separation of concerns, making the code difficult to maintain and test.

-   **Global Variables**: A global application object (`CWordPadApp theApp;` in `wordpad.cpp`) is used to manage application-level state and behavior, which is an outdated practice that hinders testability and modularity.

-   **Duplicated Logic**: There are instances of duplicated logic, particularly in areas like UI handling and file processing, which could be consolidated.

## 4. Modernization Targets

-   **Language**:
    -   Adopt **C++17** or later.
    -   Replace raw pointers with **smart pointers** (`std::unique_ptr`, `std::shared_ptr`).
    -   Replace C-style strings (`TCHAR`, `LPTSTR`) and `CString` with modern C++ string types. Adopt **`std::string`** with UTF-8 encoding for internal logic and use **`std::wstring`** for interoperability with Windows APIs that require UTF-16. Implement clear conversion routines at the boundary between the application and the operating system.
    -   Enforce **RAII** for all resource management.

-   **Build System**:
    -   Migrate the project from the Visual Studio solution (`.sln`) to **CMake**. This will enable cross-platform builds, simplify dependency management, and integrate with modern CI/CD pipelines.

-   **Architecture**:
    -   Refactor to a modern architectural pattern like **Model-View-ViewModel (MVVM)** to decouple the UI from the application logic.
    -   Introduce a **data model** layer to properly represent the document, separating it from the UI's rich edit control.
    -   Use **dependency injection** to decouple components and improve testability.
    -   Create an **abstraction layer** over platform-specific APIs to improve portability.
