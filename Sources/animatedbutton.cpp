include "AnimatedButton.h"
#include <QEvent>

AnimatedButton::AnimatedButton(QWidget *parent)
    : QPushButton(parent)
{
    originalGeometry = geometry();
}

bool AnimatedButton::event(QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        animate(true);
    } else if (event->type() == QEvent::Leave) {
        animate(false);
    }

    return QPushButton::event(event);
}

void AnimatedButton::animate(bool scaleUp)
{
    QPropertyAnimation *anim = new QPropertyAnimation(this, "geometry");
    anim->setDuration(200);

    QRect current = geometry();

    if (scaleUp) {
        int w = originalGeometry.width() * 1.1;
        int h = originalGeometry.height() * 1.1;
        int dx = (w - originalGeometry.width()) / 2;
        int dy = (h - originalGeometry.height()) / 2;

        QRect scaled(originalGeometry.x() - dx,originalGeometry.y() - dy, w, h);

        anim->setStartValue(current);
        anim->setEndValue(scaled);
    } else {
        anim->setStartValue(current);
        anim->setEndValue(originalGeometry);
    }

    anim->start(QAbstractAnimation::DeleteWhenStopped);
}
