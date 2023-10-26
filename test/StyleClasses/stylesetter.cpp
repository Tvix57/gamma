#include "stylesetter.h"

void StyleSetter::setStyle(QWidget* target)
{
    QFile file(QDir::toNativeSeparators(STYLE_FILE_WAY));
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "Не удалось открыть файл:" << STYLE_FILE_WAY << file.errorString();
        return;
    }
    target->setStyleSheet(file.readAll());
    file.close();
}
