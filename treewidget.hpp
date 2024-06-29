// treewidget.hpp
#ifndef TREEWIDGET_HPP
#define TREEWIDGET_HPP

// #include <QWidget>
#include "tree.hpp"

class TreeWidget : public QWidget {
    Q_OBJECT

public:
    explicit TreeWidget(Tree<double>& tree, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Tree<double>& tree;
    void drawNode(QPainter& painter, Node<double>* node, int x, int y, int hSpacing, int vSpacing);
};

#endif // TREEWIDGET_HPP

// treewidget.cpp
#include "treewidget.hpp"
#include <QPainter>
#include <QFontMetrics>

TreeWidget::TreeWidget(Tree<double>& tree, QWidget* parent)
    : QWidget(parent), tree(tree) {}

void TreeWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Get the nodes of the tree
    auto nodes = tree.get_nodes();

    if (!nodes.empty()) {
        // Starting position for the root node
        int rootX = width() / 2;
        int rootY = 50;
        int hSpacing = 50;
        int vSpacing = 50;

        // Draw the root node
        drawNode(painter, nodes[0], rootX, rootY, hSpacing, vSpacing);
    }
}

void TreeWidget::drawNode(QPainter& painter, Node<double>* node, int x, int y, int hSpacing, int vSpacing) {
    if (node == nullptr) return;

    // Draw the node value
    QString value = QString::number(node->get_value());
    QFontMetrics fm(painter.font());
    int textWidth = fm.horizontalAdvance(value);
    int textHeight = fm.height();

    // Draw the node (circle)
    painter.drawEllipse(QPoint(x, y), textWidth, textHeight);
    painter.drawText(QPoint(x - textWidth / 2, y + textHeight / 4), value);

    // Draw the children
    int childY = y + vSpacing;
    int leftX = x - hSpacing;
    int rightX = x + hSpacing;

    // Left child
    if (node->left) {
        painter.drawLine(x, y + textHeight / 2, leftX, childY - textHeight / 2);
        drawNode(painter, node->left, leftX, childY, hSpacing / 2, vSpacing);
    }

    // Right child
    if (node->right) {
        painter.drawLine(x, y + textHeight / 2, rightX, childY - textHeight / 2);
        drawNode(painter, node->right, rightX, childY, hSpacing / 2, vSpacing);
    }
}
