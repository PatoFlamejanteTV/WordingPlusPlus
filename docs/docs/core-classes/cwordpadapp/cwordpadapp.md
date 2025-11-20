---
sidebar_position: 1
---

# CWordPadApp

`CWordPadApp` is the main application class for the WordPad project. It is derived from the `CWinAppEx` class, which is a part of the Microsoft Foundation Classes (MFC) library. This class is responsible for initializing the application, managing the main message loop, and handling application-level events.

## Key Responsibilities

*   **Application Initialization**: `CWordPadApp` initializes the application, including registering document templates and setting up the main window.
*   **Command-Line Parsing**: It handles command-line arguments, allowing users to specify files to open or other startup options.
*   **Document Management**: The class manages the different types of documents that WordPad can handle, such as Rich Text Format (RTF), plain text, and Microsoft Word documents.
*   **Printer Management**: It provides functionality for handling printer settings and notifications.
*   **Options and Settings**: `CWordPadApp` is responsible for loading and saving application-level settings, such as units of measurement and default fonts.

## Important Member Variables

| Variable              | Type                      | Description                                                                                                                                                             |
| --------------------- | ------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `cmdInfo`             | `CWordPadCommandLineInfo` | An instance of a custom command-line info class, used to parse and store command-line arguments.                                                                      |
| `m_dcScreen`          | `CDC`                     | A device context for the screen, which can be used for querying screen properties.                                                                                     |
| `m_lf`                | `LOGFONT`                 | A structure that defines the attributes of a font.                                                                                                                      |
| `m_nDefFont`          | `int`                     | The index of the default font.                                                                                                                                          |
| `m_rectPageMargin`    | `CRect`                   | A rectangle that defines the page margins for printing.                                                                                                                 |
| `m_nNewDocType`       | `int`                     | The type of the new document to be created.                                                                                                                             |
| `m_optionsText`       | `CDocOptions`             | An object that stores the options for plain text documents.                                                                                                             |
| `m_optionsRTF`        | `CDocOptions`             | An object that stores the options for RTF documents.                                                                                                                    |

## Key Functions

### `InitInstance()`

This is one of the most important functions in the `CWordPadApp` class. It is called when the application starts and is responsible for:

*   Initializing the OLE libraries.
*   Creating the document template, which associates documents, views, and frame windows.
*   Parsing the command line to check for any file paths or switches.
*   Creating the main window and showing it.

**Example from `wordpad.cpp`:**

```cpp
BOOL CWordPadApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(10);  // Load standard INI file options (including MRU)

	//PreLoadState ();

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CWordPadDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CWordPadView));
	pDocTemplate->SetContainerInfo(IDR_CNTR_INPLACE);
	pDocTemplate->SetServerInfo(
		IDR_SRVR_EMBEDDED, IDR_SRVR_INPLACE,
		RUNTIME_CLASS(CInPlaceFrame));
	AddDocTemplate(pDocTemplate);

	// Connect the COleTemplateServer to the document template
	//  The COleTemplateServer creates new documents on behalf
	//  of requesting OLE containers
	m_server.ConnectTemplate(clsid, pDocTemplate, TRUE);
		// Note: SDI applications register server objects only if /Embedding
		//   or /Automation is present on the command line

	// Parse command line for standard shell commands, DDE, file open
	ParseCommandLine(cmdInfo);

	// Check to see if launched as OLE server
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Application was run with /Embedding or /Automation.  Don't show the
		//  main window in this case.
		return TRUE;
	}
	m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
	COleObjectFactory::UpdateRegistryAll();


	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// The main window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}
```

### `ExitInstance()`

This function is called when the application is about to terminate. It is a good place to perform any cleanup tasks, such as saving application settings.

**Example from `wordpad.cpp`:**

```cpp
int CWordPadApp::ExitInstance()
{
	SaveOptions();
	return CWinAppEx::ExitInstance();
}
```

### `ParseParam()`

This is a virtual function of the `CCommandLineInfo` class that is overridden in `CWordPadCommandLineInfo` to handle custom command-line switches. In WordPad, it is used to process switches like `/t` to force text mode.

**Example from `wordpad.cpp`:**

```cpp
void CWordPadCommandLineInfo::ParseParam(const char* pszParam,
	BOOL bFlag, BOOL bLast)
{
	if (bFlag)
	{
		if (lstrcmpi(pszParam, _T("t"))==0)
			m_bForceTextMode = TRUE;
	}
	CCommandLineInfo::ParseParam(pszParam, bFlag, bLast);
}
```

## How It's Used in WordPad

The `CWordPadApp` class is the backbone of the WordPad application. It ties together all the different components, from the user interface to the document management system. When you launch WordPad, it's the `InitInstance()` function that gets everything up and running. When you open a file, `CWordPadApp` is involved in determining the file type and creating the appropriate document object. And when you close the application, `ExitInstance()` ensures that your settings are saved for the next session.

Understanding the `CWordPadApp` class is the first step to understanding how the entire WordPad application works. It provides a high-level view of the application's architecture and is a great starting point for anyone looking to modify or extend WordPad's functionality.
