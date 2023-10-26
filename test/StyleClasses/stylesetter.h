#ifndef STYLESETTER_H
#define STYLESETTER_H

#include <QWidget>
#include <QDir>

#define STYLE_FILE_WAY ":/Styles/styles/Style.css"

class StyleSetter
{
public:
    StyleSetter() = delete;
    static void setStyle(QWidget* target = nullptr);
};

#endif // STYLESETTER_H
