cmake_minimum_required(VERSION 3.16)

project(DSA VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DSA
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        secondwindow1.h secondwindow1.cpp secondwindow1.ui


        account.h
        accountmeth.h
        customer.h
        customermeth.h
        data.h
        employee.h
        employeemeth.h
        loan.h
        loanlist.h
        loanmeth.h
        thirdwindow12.h thirdwindow12.cpp thirdwindow12.ui


        transaction.h
        transactionmeth.h
        statisticsmeth.h
        accountmeth.cpp

        customermeth.cpp
        data.cpp
        employeemeth.cpp
        loanmeth.cpp
        statisticsmeth.cpp
        transactionmeth.cpp
        deposit.h deposit.cpp deposit.ui


        dailytransaction.h dailytransaction.cpp dailytransaction.ui


        money.h money.cpp money.ui
        showloans.h showloans.cpp showloans.ui
        requestloan.h requestloan.cpp requestloan.ui
        afterregistering.h afterregistering.cpp afterregistering.ui
        secondwindow2.h secondwindow2.cpp secondwindow2.ui



        thirdwindow11.h thirdwindow11.cpp thirdwindow11.ui
        pic.qrc


        fire.h fire.cpp fire.ui
        managermenu.h managermenu.cpp managermenu.ui
        modify.h modify.cpp modify.ui
        add.h add.cpp add.ui

        secondwindow3.h secondwindow3.cpp secondwindow3.ui
        stats.h stats.cpp stats.ui
        displayemployee.h displayemployee.cpp displayemployee.ui
        functions.h
        functions.cpp
        datee.cpp
        datae.h
        employeemenu.h employeemenu.cpp employeemenu.ui
        archieve.h archieve.cpp archieve.ui
        addcustomer.h addcustomer.cpp addcustomer.ui
        listaccount.h listaccount.cpp listaccount.ui
        listaccount.ui
        listaccount.h
        displayloans.h displayloans.cpp displayloans.ui

        loans1.h loans1.cpp loans1.ui
        manageloans.h manageloans.cpp manageloans.ui















    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DSA APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DSA SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DSA
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(DSA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DSA)
endif()
set_target_properties(DSA PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DSA
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DSA)
endif()
