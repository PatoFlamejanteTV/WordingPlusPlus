#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings : public QSettings
{
    Q_OBJECT

public:
    Settings(QObject *parent = nullptr);
    ~Settings();
};

#endif // SETTINGS_H
