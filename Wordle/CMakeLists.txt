set(WORDPAD_SOURCES
    AppContext.cpp
    DocumentModel.cpp
    AppLookDlg.cpp
    TaskPane.cpp
    buttondi.cpp
    chicdial.cpp
    cntritem.cpp
    datedial.cpp
    ddxm.cpp
    docopt.cpp
    doctype.cpp
    filenewd.cpp
    formatba.cpp
    formatpa.cpp
    formatta.cpp
    ipframe.cpp
    key.cpp
    listdlg.cpp
    mainfrm.cpp
    multconv.cpp
    options.cpp
    optionsh.cpp
    pageset.cpp
    ruler.cpp
    splash.cpp
    srvritem.cpp
    stdafx.cpp
    strings.cpp
    unitspag.cpp
    wordpad.cpp
    wordpdoc.cpp
    wordpvw.cpp
    wordpad.rc
)

add_executable(WordPad WIN32 ${WORDPAD_SOURCES})

set_property(TARGET WordPad PROPERTY VS_KEYWORD "MFCProj")

set(CMAKE_MFC_FLAG 2)

target_precompile_headers(WordPad PRIVATE stdafx.h)

target_link_libraries(WordPad PRIVATE Ole32.lib)
