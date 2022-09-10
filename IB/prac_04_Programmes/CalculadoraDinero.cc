#include <iostream>
#include <sstream>
#include <string>

int main() {
    double DineroTotal, TotalMonedas, TotalBilletes;
    double MDe1, MDe5, MDe10, MDe20, MDe50, BDe5, BDe10, BDe20, BDe50, BDe100, BDe200, BDe500;
    // la letra mayúscula M hace referencia a la palabra Monedas, y la B a Billetes
    std::string SMDe1, SMDe5, SMDe10, SMDe20, SMDe50, SBDe5, SBDe10, SBDe20, SBDe50, SBDe100, SBDe200, SBDe500;
    // la letra S mayúscula hace referencia a la palabra String, es la variable String que asociaremos a cada variable int

    std::cout << "Soy un programa que puede calcular cuanto dinero tienes ahora mismo" << std::endl
              << "Solo necesito saber cuantas monedas y billetes en Euros de cada tipo tienes" << std::endl
              << "Por favor, introduce los datos que te voy a pedir a continuación con sinceridad" <<std::endl << std::endl;
    
    std::cout << "¿Cuantas monedas de un céntimos tienes? ";
    std::cin >> SMDe1;
    std::stringstream(SMDe1) >> MDe1;
    MDe1 = MDe1*1;

    std::cout << "¿Cuantas monedas de 5 céntimos tienes? ";
    std::cin >> SMDe5;
    std::stringstream(SMDe5) >> MDe5;
    MDe5 = MDe5*5;

    std::cout << "¿Cuantas monedas de 10 céntimos tienes? ";
    std::cin >> SMDe10;
    std::stringstream(SMDe10) >> MDe10;
    MDe10 = MDe10*10;

    std::cout << "¿Cuantas monedas de 20 céntimos tienes? ";
    std::cin >> SMDe20;
    std::stringstream(SMDe20) >> MDe20;
    MDe20 = MDe20*20;

    std::cout << "¿Cuantas monedas de 50 céntimos tienes? ";
    std::cin >> SMDe50;
    std::stringstream(SMDe50) >> MDe50;
    MDe50 = MDe50*50;

    std::cout << "¿Cuantos billetes de 5 euros tienes? ";
    std::cin >> SBDe5;
    std::stringstream(SBDe5) >> BDe5;
    BDe5 = BDe5*5;

    std::cout << "¿Cuantas billetes de 10 euros tienes? ";
    std::cin >> SBDe10;
    std::stringstream(SBDe10) >> BDe10;
    BDe10 = BDe10*10;

    std::cout << "¿Cuantas billetes de 20 euros tienes? ";
    std::cin >> SBDe20;
    std::stringstream(SBDe20) >> BDe20;
    BDe20 = BDe20*20;

    std::cout << "¿Cuantas billetes de 50 euros tienes? ";
    std::cin >> SBDe50;
    std::stringstream(SBDe50) >> BDe50;
    BDe50 = BDe50*50;

    std::cout << "¿Cuantas billetes de 100 euros tienes? ";
    std::cin >> SBDe100;
    std::stringstream(SBDe100) >> BDe100;
    BDe100 = BDe100*100;

    std::cout << "¿Cuantas billetes de 200 euros tienes? ";
    std::cin >> SBDe200;
    std::stringstream(SBDe200) >> BDe200;
    BDe200 = BDe200*200;

    std::cout << "¿Cuantas billetes de 500 euros tienes? ";
    std::cin >> SBDe500;
    std::stringstream(SBDe500) >> BDe500;
    BDe500 = BDe500*500;
 
    DineroTotal = 0;
    TotalMonedas = MDe1+MDe5+MDe10+MDe20+MDe50;
    TotalBilletes = BDe5+BDe10+BDe20+BDe50+BDe100+BDe200+BDe500;
    DineroTotal = TotalBilletes+(TotalMonedas/100);

    std::cout << "Tienes " << DineroTotal << " Euros" << std::endl;

    return 0;
}