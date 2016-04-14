#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include "gameplay.h"
using namespace gameplay;

#include <QMainWindow>
#include <QToolButton>

namespace Ui {
class EditorWindow;
}

class ProjectWizard;
class ProjectView;
class GameView;
class SceneView;
class PropertiesView;
class Project;

/**
 * Main editor window.
 */
class EditorWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * Constructor.
     *
     * @param parent The parent widget.
     */
    explicit EditorWindow(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~EditorWindow();

    /**
     * Gets the asset path for the project.
     *
     * @return The asset path.
     */
    const std::string& getAssetPath() const;

    /**
     * Sets the project wizard.
     *
     * @param projectWizard
     */
    void setProjectWizard(ProjectWizard* projectWizard);

    /**
     * Gets the opened project.
     *
     * @return The currently open project.
     */
    Project* project() const;

    /**
     * Gets the opened scene.
     *
     * @return The open scene.
     */
    Scene* scene() const;

public slots:
    /**
     * Handler for opening a project.
     *
     * @param path The path to the project opened.
     */
    void projectOpened(const QString& path);

    /**
     * Handler for opening a scene.
     *
     * @param path The path to the scene opened.
     */
    void sceneOpened(const QString& path);

    /**
     * Action open triggered from menu.
     */
    void actionOpenTriggered();

    /**
     * Action new triggered from menu.
     */
    void actionNewTriggered();

    /**
     * Action when actionFullscreen is toggled.
     *
     * @param enabled true if enabled
     */
    void actionFullscreenToggled(bool enabled);

    /**
     * Action when transform mode world is triggered.
     */
    void actionTransformModeWorldTriggered();

    /**
     * Action when transform mode local is triggered.
     */
    void actionTransformModeLocalTriggered();

    /**
     * Action when shading lit is triggered.
     */
    void actionShadingLitTriggered();

    /**
     * Action when shading unlit is triggered.
     */
    void actionShadingUnlitTriggered();

    /**
     * Action when shading wireframe is triggered.
     */
    void actionShadingWireframeTriggered();

signals:
    /**
     * Signal emitted when the project changes.
     */
    void projectChanged();

    /**
     * Signal emitted when the scene changes.
     */
    void sceneChanged();

private:
    Ui::EditorWindow* _ui;
    GameView* _gameView;
    ProjectWizard* _projectWizard;
    ProjectView* _projectView;
    PropertiesView *_propertiesView;
    SceneView*_sceneView;
    Scene* _scene;
    QToolButton* _transformModeButton;
    QToolButton* _shadingButton;
    std::string _assetPath;
};

#endif
