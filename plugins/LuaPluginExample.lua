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
