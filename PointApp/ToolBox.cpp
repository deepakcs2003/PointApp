#include "ToolBox.h"
#include <QVBoxLayout>
#include <QToolButton>
#include <QFrame>
#include <QIcon>
#include <QLabel>
#include <QFont>

ToolBox::ToolBox(QWidget* parent) : QWidget(parent)
{
    createTools();
}
    
ToolBox::~ToolBox()
{
}

void ToolBox::createTools()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(6, 10, 6, 10);
    layout->setSpacing(6);

    struct Tool {
        QString name;
        QString icon;
    };

    QList<Tool> group1 = {
        {"Move",  ":/icons/icons/move.svg"},
        {"Rot",   ":/icons/icons/rot.svg"},
        {"Scale", ":/icons/icons/scale.svg"}
    };

    QList<Tool> group2 = {
        {"Cuboid", ":/icons/icons/cuboid.svg"},
        {"Sphere", ":/icons/icons/sphere.svg"},
        {"Cyl",    ":/icons/icons/cyl.svg"},
        {"Cone",   ":/icons/icons/cone.svg"},
        {"Line",   ":/icons/icons/line.svg"}
    };

    QList<Tool> group3 = {
        {"Grp",  ":/icons/icons/grp.svg"},
        {"Lock", ":/icons/icons/lock.svg"},
        {"Del",  ":/icons/icons/del.svg"}
    };

    auto makeButton = [&](const Tool& tool)
        {
            QToolButton* btn = new QToolButton;

            btn->setText(tool.name.toUpper());
            btn->setIcon(QIcon(tool.icon));
            btn->setIconSize(QSize(26, 26));
            btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            btn->setFixedSize(70, 60);
            btn->setCheckable(true);

            connect(btn, &QToolButton::clicked, this, [=]()
                {
                    for (QToolButton* other : findChildren<QToolButton*>())
                    {
                        if (other != btn)
                            other->setChecked(false);
                    }

                    emit toolSelected(tool.name);
                });

            layout->addWidget(btn, 0, Qt::AlignHCenter);
        };

    auto addGroupTitle = [&](QString title)
        {
            QLabel* label = new QLabel(title);
            label->setAlignment(Qt::AlignCenter);

            QFont f = label->font();
            f.setBold(true);
            f.setPointSize(10);
            label->setFont(f);

            layout->addSpacing(4);
            layout->addWidget(label);
        };

    auto addSeparator = [&]()
        {
            QFrame* line = new QFrame;
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            layout->addWidget(line);
        };

    // Group 1
    addGroupTitle("Transform");
    for (auto& t : group1) makeButton(t);

    addSeparator();

    // Group 2
    addGroupTitle("Shapes");
    for (auto& t : group2) makeButton(t);

    addSeparator();

    // Group 3
    addGroupTitle("Object");
    for (auto& t : group3) makeButton(t);

    layout->addStretch();

    setLayout(layout);
}