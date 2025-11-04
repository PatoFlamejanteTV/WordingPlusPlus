# Plugin API Documentation

This document outlines the API for creating plugins for the WordPad application.

## C++ Plugins

C++ plugins are created as DLLs and must export a `CreatePlugin` function that returns a pointer to an object that implements the `IPlugin` interface.

### `IPlugin` Interface

```cpp
class IPlugin
{
public:
    virtual ~IPlugin() = default;

    virtual const wchar_t* GetPluginName() const = 0;
    virtual const wchar_t* GetPluginAuthor() const = 0;
    virtual const wchar_t* GetPluginDescription() const = 0;
    virtual const wchar_t* GetPluginVersion() const = 0;
    virtual void Execute(CWordPadView* pView) = 0;
};
```

### `CWordPadView` API

The `CWordPadView` object passed to the `Execute` function provides the following methods for interacting with the document:

- `std::wstring GetSelectedText()`: Returns the currently selected text.
- `void ReplaceSelectedText(const std::wstring& text)`: Replaces the currently selected text with the provided text.

## Lua Plugins

Lua plugins are scripts that return a table with the following fields:

- `name`: The name of the plugin.
- `author`: The author of the plugin.
- `description`: A description of the plugin.
- `version`: The version of the plugin.
- `Execute`: A function that takes a `CWordPadView` object as an argument.

### Example Lua Plugin

```lua
-- Example Lua Plugin for WordPad

-- Plugin metadata
local plugin = {
    name = "Lua Uppercase Plugin",
    author = "Jules",
    description = "Converts the selected text to uppercase.",
    version = "1.0"
}

-- Execute function that will be called by the application
function plugin.Execute(view)
    -- Get the currently selected text
    local selectedText = view:GetSelectedText()

    -- Check if there is any selected text
    if #selectedText > 0 then
        -- Convert the text to uppercase
        local upperText = string.upper(selectedText)
        -- Replace the selected text with the uppercase version
        view:ReplaceSelectedText(upperText)
    end
end

-- Return the plugin table so the PluginManager can register it
return plugin
```
