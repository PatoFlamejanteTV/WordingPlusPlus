#pragma once

#include <string>

class CWordPadView;

class IPlugin
{
public:
    virtual ~IPlugin() = default;
    virtual std::wstring GetName() const = 0;
    virtual std::wstring GetAuthor() const = 0;
    virtual std::wstring GetDescription() const = 0;
    virtual void Execute(CWordPadView* pView) = 0;
};
