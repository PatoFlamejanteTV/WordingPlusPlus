---
sidebar_position: 3
---

# CWordPadView

The `CWordPadView` class is the view class for the WordPad application. It is derived from `CRichEditView`, which is a part of the Microsoft Foundation Classes (MFC) library. This class is responsible for displaying the document's data to the user and for handling user input, such as keyboard and mouse events.

## Key Responsibilities

*   **Data Rendering**: `CWordPadView` is responsible for rendering the content of the document in the client area of the application's window.
*   **User Input Handling**: It handles all user input, including keyboard strokes, mouse clicks, and menu selections.
*   **View Updates**: The class ensures that the view is always up-to-date with the latest changes in the document's data.
*   **Printing**: `CWordPadView` manages the printing process, including formatting the document for the printer and handling print preview.

## Important Member Variables

| Variable          | Type          | Description                                                                                                                                                             |
| ----------------- | ------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `m_uTimerID`      | `UINT_PTR`    | The ID of a timer that is used to delay the updating of certain UI elements, such as the ruler.                                                                        |
| `m_bDelayUpdateItems` | `BOOL`        | A boolean flag that indicates whether the updating of UI elements should be delayed.                                                                                 |
| `m_bInPrint`      | `BOOL`        | A boolean flag that is set to `TRUE` when the view is in the process of printing.                                                                                        |
| `m_defParaFormat` | `CParaFormat` | A `CParaFormat` object that stores the default paragraph formatting for the document.                                                                                   |
| `m_defCharFormat` | `CCharFormat` | A `CCharFormat` object that stores the default character formatting for the document.                                                                                   |

## Key Functions

### `OnPrint()`

This function is called by the framework to print or preview a page of the document. It is responsible for rendering the specified page to a device context.

**Example from `wordpvw.cpp`:**

```cpp
void CWordPadView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// ... (code to prepare for printing)

	// Print the page
	CRichEditView::OnPrint(pDC, pInfo);

	// ... (code to clean up after printing)
}
```

### `OnPreparePrinting()`

This function is called by the framework before printing or print preview begins. It is a good place to initialize the print dialog box and to set the printing parameters.

**Example from `wordpvw.cpp`:**

```cpp
BOOL CWordPadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}
```

### `WrapChanged()`

This function is called when the wrapping settings of the document have changed. It is responsible for updating the view to reflect the new wrapping settings.

**Example from `wordpvw.cpp`:**

```cpp
void CWordPadView::WrapChanged()
{
	// ... (code to update the view)
}
```

## How It's Used in WordPad

The `CWordPadView` class is the user's window into the document. It is the class that is responsible for everything the user sees and interacts with. When you type text into the editor, it is the `CWordPadView` class that is handling the keyboard events and displaying the text on the screen. When you select a piece of text and apply formatting, it is the view that is responsible for rendering the text with the new formatting.

The `CWordPadView` class works closely with the `CWordPadDoc` class to ensure that the visual representation of the document is always in sync with the underlying data. When the document's data is modified, the document class calls the view's `OnUpdate()` function to notify it that it needs to be redrawn. This separation of the data from its presentation is a powerful feature of the document/view architecture and is what makes it possible to have multiple views of the same document.
