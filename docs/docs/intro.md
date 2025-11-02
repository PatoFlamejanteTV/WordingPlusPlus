---
sidebar_position: 1
---

# WordPad Contributor Guide

Welcome to the WordPad Contributor Guide! This documentation is designed to help you understand the inner workings of the WordPad application, providing a comprehensive overview of its architecture, core components, and development practices. Whether you're a seasoned MFC developer or new to the framework, this guide will provide the insights you need to contribute effectively.

## Understanding the Architecture

WordPad is a classic C++ application built on the **Microsoft Foundation Classes (MFC)** framework. At the heart of its design is the **document/view architecture**, a powerful pattern that separates data management from its visual representation. This separation is key to creating a modular and extensible application.

### The Document/View Model

The document/view model is a design pattern that structures an application into three main components:

-   **The Document (`CWordPadDoc`)**: This object is responsible for managing the application's data. It handles file operations like opening, saving, and serializing data to and from storage. The document is the central repository for the application's state and is completely independent of the user interface.

-   **The View (`CWordPadView`)**: This object is responsible for rendering the document's data and handling user interactions. It's the visual representation of the document, displaying the content in a window and responding to user input such as mouse clicks and keyboard entries. A single document can have multiple views, each providing a different perspective on the same data.

-   **The Frame Window (`CMainFrame`)**: This object acts as the container for the views and other UI elements like toolbars, menus, and status bars. It manages the application's main window and coordinates communication between the various UI components.

### How They Work Together

The document/view model is designed to ensure a clean separation of concerns. Here’s a typical workflow:

1.  **User Action**: The user interacts with the view (e.g., by typing text or selecting a menu item).
2.  **View to Document**: The view interprets the user's action and, if necessary, sends a command to the document to update its data.
3.  **Document Update**: The document modifies its data in response to the command.
4.  **Document to Views**: Once the data is updated, the document notifies all its associated views that a change has occurred by calling their `UpdateAllViews()` method.
5.  **View Redraw**: Each view, upon receiving the update notification, queries the document for the latest data and redraws itself to reflect the changes.

This decoupled architecture makes the application more robust and easier to maintain. For example, you could add a new view that displays the document's statistics without having to modify the core document class.

## Core Classes

To get started with the WordPad codebase, you should familiarize yourself with the following core classes:

-   **`CWordPadApp`**: The main application class that orchestrates the entire application.
-   **`CWordPadDoc`**: The document class that manages the document's data.
-   **`CWordPadView`**: The view class that renders the document and handles user input.

You can find detailed documentation for each of these classes in the "Core Classes" section of this guide.

## Getting Started

Before you start coding, we recommend that you take some time to explore the codebase and familiarize yourself with the project's structure. This guide is a great place to start, but there's no substitute for reading the code itself.

Happy coding!
