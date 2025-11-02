---
sidebar_position: 2
---

# CWordPadDoc

The `CWordPadDoc` class is the document class for the WordPad application. It is derived from `CRichEditDoc`, which is a part of the Microsoft Foundation Classes (MFC) library. This class is responsible for managing the data associated with a document, including loading, saving, and serializing the content.

## Key Responsibilities

*   **Data Management**: `CWordPadDoc` is the central hub for the document's data. It holds the content of the file and is responsible for its integrity.
*   **Serialization**: It handles the process of reading the document's data from a file (deserialization) and writing it back to a file (serialization).
*   **Document Type Management**: The class is aware of the different document types that WordPad can handle, such as Rich Text Format (RTF), plain text, and Microsoft Word documents.
*   **View Coordination**: `CWordPadDoc` communicates with the `CWordPadView` class to ensure that the visual representation of the document is always in sync with the underlying data.

## Important Member Variables

| Variable      | Type  | Description                                                                                                                                                                             |
| ------------- | ----- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `m_nDocType`  | `int` | An integer that represents the current type of the document. This can be one of several predefined types, such as `RD_WINWORD6`, `RD_RICHTEXT`, or `RD_TEXT`.                               |
| `m_nNewDocType` | `int` | An integer that stores the type of a new document that is about to be created. This is used when the user selects a different document type in the "New" dialog.                      |

## Key Functions

### `OnNewDocument()`

This function is called when a new document is created. It is responsible for initializing the document's data and setting its default properties. In WordPad, it sets the document type to the default and calls the base class implementation to complete the process.

**Example from `wordpdoc.cpp`:**

```cpp
BOOL CWordPadDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	SetDocType(theApp.m_nNewDocType, TRUE);
	return TRUE;
}
```

### `OnOpenDocument()`

This function is called when an existing document is opened. It is responsible for opening the specified file, reading its contents, and initializing the document's data. In WordPad, it determines the document type based on the file's content and then calls the base class implementation.

**Example from `wordpdoc.cpp`:**

```cpp
BOOL CWordPadDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	// CFileException is used here to get error information
	CFileException fe;
	CFile* pFile = GetFile(lpszPathName,
		CFile::modeRead|CFile::shareDenyWrite, &fe);
	if (pFile == NULL)
	{
		ReportSaveLoadException(lpszPathName, &fe, FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
		return FALSE;
	}

	CArchive loadArchive(pFile, CArchive::load | CArchive::bNoFlushOnDelete);
	loadArchive.m_pDocument = this;
	loadArchive.m_bForceFlat = FALSE;
	TRY
	{
		// determine file type
		Serialize(loadArchive);
		loadArchive.Close();
		delete pFile;
	}
	CATCH_ALL(e)
	{
		delete pFile;
		ReportSaveLoadException(lpszPathName, e, FALSE,
			AFX_IDP_FAILED_TO_OPEN_DOC);
		DELETE_EXCEPTION(e);
		return FALSE;
	}
	END_CATCH_ALL

	SetModifiedFlag(FALSE);     // start off with unmodified

	return TRUE;
}
```

### `Serialize()`

This function is at the heart of the document's persistence mechanism. It is called by the framework to either read the document's data from an archive (loading) or write it to an archive (saving). The implementation in `CWordPadDoc` delegates the heavy lifting to the base class, `CRichEditDoc`, which handles the actual serialization of the rich text content. The `CWordPadDoc` override primarily manages the OLE message filter to prevent busy dialogs from appearing during the serialization process.

**Example from `wordpdoc.cpp`:**
```cpp
void CWordPadDoc::Serialize(CArchive& ar)
{
	COleMessageFilter* pFilter = AfxOleGetMessageFilter();
	ASSERT(pFilter != NULL);
	if (pFilter != NULL)
	{
		pFilter->EnableBusyDialog(FALSE);
		if (ar.IsLoading())
			SetDocType(m_nNewDocType);
		CRichEditDoc::Serialize(ar);
		pFilter->EnableBusyDialog(TRUE);
	}
}
```

## How It's Used in WordPad

The `CWordPadDoc` class is the silent workhorse of the WordPad application. While the user interacts with the view (`CWordPadView`), the document class is busy in the background, managing the data and ensuring that it is saved and loaded correctly. When you open a file, `OnOpenDocument()` is called to read the data from the disk. When you save your work, `DoSave()` and `Serialize()` are called to write the data back to the disk.

The separation of the document and the view is a key concept in MFC's document/view architecture. It allows for multiple views of the same data and makes the application more modular and easier to maintain. Understanding the role of `CWordPadDoc` is essential for anyone who wants to work with the data side of the WordPad application, such as implementing a new file format or adding custom data to the document.
