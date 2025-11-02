---
sidebar_position: 1
---

# How to Add a New Feature: A Word Count Example

This guide will walk you through the process of adding a new feature to the WordPad application. We will use a simple "Word Count" utility as an example to illustrate the key steps involved in modifying the codebase. By the end of this tutorial, you will have a better understanding of how to add new functionality to WordPad.

## Step 1: Add a New Menu Item

The first step is to add a new menu item to the application's user interface. In WordPad, the menus are defined in the `wordpad.rc` file.

1.  **Open `wordpad.rc`**: Locate and open the `wordpad.rc` file in the `Wordle` directory. This is a resource script file that defines the application's resources, including menus, dialog boxes, and icons.

2.  **Find the Main Menu**: Search for the `IDR_MAINFRAME` menu resource in the `wordpad.rc` file. This is the main menu for the application.

3.  **Add the New Menu Item**: Add a new menu item to the "View" menu. You can do this by adding the following line to the `POPUP "&View"` section:

    ```rc
    MENUITEM "&Word Count", ID_VIEW_WORD_COUNT
    ```

4.  **Define the Command ID**: You will also need to define the `ID_VIEW_WORD_COUNT` command ID in the `resource.h` file. This is a unique identifier that will be used to associate the menu item with a command handler function.

    ```cpp
    #define ID_VIEW_WORD_COUNT 200
    ```

## Step 2: Handle the Menu Command

Now that you have added the new menu item, you need to add a command handler function to respond to it when it is clicked. In WordPad, the command handlers for view-related commands are located in the `CWordPadView` class.

1.  **Open `wordpvw.h`**: Open the `wordpvw.h` file and add a declaration for the new command handler function to the `CWordPadView` class.

    ```cpp
    afx_msg void OnViewWordCount();
    ```

2.  **Open `wordpvw.cpp`**: Open the `wordpvw.cpp` file and add the new command handler function to the message map of the `CWordPadView` class.

    ```cpp
    ON_COMMAND(ID_VIEW_WORD_COUNT, OnViewWordCount)
    ```

3.  **Implement the Command Handler**: Add the implementation of the `OnViewWordCount()` function to the `wordpvw.cpp` file.

    ```cpp
    void CWordPadView::OnViewWordCount()
    {
        // TODO: Add your command handler code here
    }
    ```

## Step 3: Implement the Feature Logic

Now that you have the menu item and the command handler in place, you can implement the logic for the "Word Count" feature.

1.  **Get the Text**: The first step is to get the text from the document. You can do this by using the `GetText()` function of the `CRichEditCtrl` class, which is the base class for `CWordPadView`.

2.  **Count the Words**: Once you have the text, you can count the words. A simple way to do this is to iterate through the text and count the number of spaces.

3.  **Display the Result**: Finally, you can display the word count to the user in a message box.

Here is the complete implementation of the `OnViewWordCount()` function:

```cpp
void CWordPadView::OnViewWordCount()
{
    // Get the text from the rich edit control
    CString strText;
    GetWindowText(strText);

    // Count the words
    int nWordCount = 0;
    BOOL bInWord = FALSE;
    for (int i = 0; i < strText.GetLength(); i++)
    {
        if (isspace(strText[i]))
        {
            bInWord = FALSE;
        }
        else if (!bInWord)
        {
            bInWord = TRUE;
            nWordCount++;
        }
    }

    // Display the result
    CString strMsg;
    strMsg.Format(_T("Word count: %d"), nWordCount);
    MessageBox(strMsg);
}
```

## Conclusion

Congratulations! You have successfully added a new "Word Count" feature to the WordPad application. You have learned how to add a new menu item, handle a menu command, and implement the logic for a simple feature. This is just a starting point, and there are many other ways that you can extend the functionality of WordPad. We encourage you to explore the codebase and to experiment with adding your own features.
