#include <QApplication>
#include <QPushButton>
/*int main(int argc, char **argv){
    QApplication app(argc, argv);
    QPushButton button;
    //* QFont(const QString & family, int pointSize = –1, int weight = -1, bool italic = false)
    
    QFont font("Courier",0,1,false);
    button.setText("My Text");
    button.setToolTip("A tooltip");
    button.setFont(font);
    QIcon icon ("D:/Icons/Fav_icon.png");
    button.setIcon(icon);
    //button.show();
    QPushButton btn1("test");
    QPushButton btn2("other", &btn1);
    btn1.show();
    
    return app.exec();
}*/
int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QWidget window;
 window.setFixedSize(100, 50);

 QPushButton *button = new QPushButton("Hello World", &window);
 button->setGeometry(10, 10, 80, 30);

 window.show();
 return app.exec();
}