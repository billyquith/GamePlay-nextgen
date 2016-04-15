#ifndef PROJECTSROTFILTERPROXYMODEL_H
#define PROJECTSROTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

/**
 * Defines the sorting filter used for the project.
 */
class ProjectSortFilterProxyModel : public QSortFilterProxyModel
{
public:
    /**
     * Constructor.
     *
     * @param parent The parent object.
     */
    explicit ProjectSortFilterProxyModel(QObject* parent = nullptr);

    /**
     * Destructor.
     */
    ~ProjectSortFilterProxyModel();

    /**
     * @see QSortFilterProxyModel::lessThan
     */
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};

#endif