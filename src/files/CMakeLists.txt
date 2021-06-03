
add_executable(ModelView
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    mymodel.cpp
    mymodel.h
    dialog.cpp
    dialog.h
    dialog.ui
    renderarea.cpp
    renderarea.h
)
target_link_libraries(ModelView Qt5::Widgets)
