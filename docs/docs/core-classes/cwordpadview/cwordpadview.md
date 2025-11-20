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

This function is called by the framework to print or preview a page of the document. It is responsible for rendering the specified page to a device context. In `CWordPadView`, this function is also used to draw the page margins when in print preview mode.

**Example from `wordpvw.cpp`:**

```cpp
void CWordPadView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CRichEditView::OnPrint(pDC, pInfo);
	if (pInfo != NULL && pInfo->m_bPreview)
		DrawMargins(pDC);
}
```

### `OnPreparePrinting()`

This function is called by the framework before printing or print preview begins. It is a good place to initialize the print dialog box and to set the printing parameters. The `CWordPadView` implementation simply calls the `DoPreparePrinting` helper function, which is a part of the MFC framework.

**Example from `wordpvw.cpp`:**

```cpp
BOOL CWordPadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}
```

### `WrapChanged()`

This function is called when the wrapping settings of the document have changed. It is responsible for updating the view to reflect the new wrapping settings. The `CWordPadView` implementation displays a "Formatting" message to the user, calls the base class implementation to perform the actual wrapping, and then restores the idle message.

**Example from `wordpvw.cpp`:**

```cpp
void CWordPadView::WrapChanged()
{
	CWaitCursor wait;
	CFrameWnd* pFrameWnd = GetParentFrame();
	ASSERT(pFrameWnd != NULL);
	if (pFrameWnd)
	{
		pFrameWnd->SetMessageText(IDS_FORMATTING);
		CWnd* pBarWnd = pFrameWnd->GetMessageBar();
		if (pBarWnd != NULL)
			pBarWnd->UpdateWindow();

		CRichEditView::WrapChanged();

		pFrameWnd->SetMessageText(AFX_IDS_IDLEMESSAGE);
		if (pBarWnd != NULL)
			pBarWnd->UpdateWindow();
	}
}
```

## How It's Used in WordPad

The `CWordPadView` class is the user's window into the document. It is the class that is responsible for everything the user sees and interacts with. When you type text into the editor, it is the `CWordPadView` class that is handling the keyboard events and displaying the text on the screen. When you select a piece of text and apply formatting, it is the view that is responsible for rendering the text with the new formatting.

The `CWordPadView` class works closely with the `CWordPadDoc` class to ensure that the visual representation of the document is always in sync with the underlying data. When the document's data is modified, the document class calls the view's `OnUpdate()` function to notify it that it needs to be redrawn. This separation of the data from its presentation is a powerful feature of the document/view architecture and is what makes it possible to have multiple views of the same document.
