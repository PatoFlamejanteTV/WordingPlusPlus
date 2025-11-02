# Overarching Strategic Goal
The primary objective of this modernization effort is to modernize the WordPad application on the Windows platform, improving maintainability and developer experience. While cross-platform compatibility is a long-term consideration, the initial focus will be on creating a robust, modern, and testable Windows application.

# Prioritized Refactoring Plan

This plan outlines a prioritized approach to modernizing the WordPad codebase, building on the findings from the `MODERNIZATION_REPORT.md`.

1.  **Core Architecture & Build System**:
    *   **Migrate to CMake**: Convert the existing Visual Studio project (`.sln`, `.vcxproj`) to a `CMakeLists.txt`. This is a foundational step that will enable automated builds and easier integration of third-party libraries.
    *   **Introduce a Modern Architectural Pattern**: Begin decoupling the core components.
        *   Start by creating a dedicated **document model** class that is independent of the MFC `CRichEditDoc`. This class will encapsulate the document's data and business logic.
        *   Refactor `CWordPadApp` to reduce its role as a container of global state. Introduce a dependency injection framework or service locator to manage dependencies.

2.  **Document Handling**:
    *   **Refactor `CWordPadDoc`**: Modify `CWordPadDoc` to act as a bridge between the new document model and the MFC framework. Its primary role should be to coordinate between the model and the view, not to contain business logic.
    *   **Modernize File I/O**: Replace the existing file loading/saving mechanisms which are tightly coupled with MFC's `CArchive`. Since WordPad handles complex formats like RTF, a direct replacement with `std::fstream` is not feasible. The new implementation must incorporate a robust RTF parser/writer library or define a modern C++-friendly abstraction over the Win32 Rich Edit control's streaming capabilities (`EM_STREAMIN`/`EM_STREAMOUT`).

3.  **UI Components**:
    *   **Decouple the View**: Refactor `CWordPadView` to be a "dumb" view. It should be responsible for rendering the document model, but not for modifying it directly. User interactions should be forwarded to a **ViewModel** layer.
    *   **Abstract Rendering**: Create an abstraction layer over the GDI-based rendering in `CWordPadView`. This will pave the way for replacing GDI with a modern graphics library (e.g., Skia, Direct2D) without requiring a full rewrite of the view logic.
    *   **Modernize UI Components**: Systematically replace legacy UI components like the format bar (`CFormatBar`) and ruler (`CRulerBar`) with modern equivalents, ideally from a cross-platform UI toolkit like Qt or wxWidgets, if a full UI overhaul is desired.

4.  **Language Modernization**:
    *   **Adopt C++17**: Configure the build system to use the C++17 standard.
    *   **Incremental Refactoring**:
        *   Replace raw pointers with smart pointers (`std::unique_ptr`, `std::shared_ptr`) in newly refactored components.
        *   Use `std::string` and `std::string_view` for all new string manipulations.
        *   Apply the RAII pattern consistently for resource management in refactored code.
