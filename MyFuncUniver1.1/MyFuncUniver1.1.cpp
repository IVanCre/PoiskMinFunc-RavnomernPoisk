
#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

int i;
double y;


double f1(double x)// 0,1 
{
	y = sqrt(1 + (pow(x, 2))) + exp(-2 * x);
	return y;
}
double f2(double x)//-1,0 +
{
	y = pow(x, 4) + 2 * (pow(x, 2)) + 4 * x + 1;
	return y;
}
double f3(double x)//3,5 /+
{
	y = pow(x, 4) - 10 * (pow(x, 3)) + 36 * (pow(x, 2)) + 5 * x;
	return y;
}
double f4(double x)//3,5/+
{
	y = pow(x, 4) + 2 * (pow(x, 2)) + 4 * x + 1;
	return y;
}
double f5(double x)//0,45/+
{
	y = log(1 + (pow(x, 2))) - sin(x);
	return y;
}
double f6(double x)//0,2/+
{
	y = 0.25 *(pow(x, 4)) + pow(x, 2) - 8 * x + 12;
	return y;
}
double f7(double x)//-2,0/+
{
	y = pow(x, 3) - x + 1;
	return y;
}
double f8(double x)//1,5 +
{
	y = 2 * (pow(x, 2)) + 16 / x;
	return y;
}
double f9(double x)//-5,0 /+
{
	y = 4 + (pow(x, 3)) + 2 * x - 3 * (pow(x, 2)) + exp(x / 2);
	return y;
}
double f10(double x)//5,20/+
{
	y = 12 * (pow(x, 2)) - (2 / 3) *(pow(x, 3));
	return y;
}
double f11(double x)//-1, 2.5/ +
{
	y = pow(x, 4) - 12 * (pow(x, 3)) + 47 * (pow(x, 2)) - 60 * x;
	return y;
}
double f12(double x)//1,5 /+
{
	y = 10 * (pow(x, 3)) + 3 * (pow(x, 2)) + x + 5;
	return y;
}
double f13(double x)//-1,0 /+
{
	y = pow(x, 4) + 2 * (pow(x, 2)) + 4 * x + 1;
	return y;
}
double f14(double x)//5,10 /+
{
	y = pow(x, 2) + exp(-x);
	return y;
}
double f15(double x)//-4,4 /+
{
	y = 2 * x + exp(-x);
	return y;
}
double f16(double x)//-10,10 /+
{
	y = pow(x, 2) + x + sin(x);
	return y;
}
double f17(double x)//-3,10/+
{
	y = pow(x, 2) - x + exp(-x);
	return y;
}
double f18(double x)//4,6/+
{
	y = 2 * (pow(x, 2)) - 5 - pow(2, x);
	return y;
}
double f19(double x)//-3,5/+
{
	y = (1 / 3) * (pow(x, 3)) + 2 * (pow(x, 2)) - 5 * x + 6;
	return y;
}
double f20(double x)//-5,10 /+
{
	y = -1 * pow(x, 2) + 5 * x - 6;
	return y;
}
double f21(double x)//-3,0 /+
{
	y = abs((abs(x*(x - 1))) - 1);
	return y;
}



double RavnPoisk(int vibor, int N, double a, double b, double Ex, double Ey, int k, double shod[], int &Schet)
{
	cout << "               Cikl programmi = " << k << endl;
	int newN = N + 1;//чтобы последний узел тоже учитывался, узлов всегда на 1 больше интервалов
	int l = 2;// массив включает точку узла и функция от этого узла- массив на 2 ячейки

	double **mas = new   double*[newN];// матрица на количество узлов и по 2 элем в кажд - X и Y
	for (i = 0; i < newN; i++)
		mas[i] = new  double[l];

	double delt = b - a;

	for (i = 0; i < newN; i++)//ищем узлы, значения в узлах, пишем все в матрицу
	{
		double xi = a + (delt / N)*i;
		mas[i][0] = xi;

		double yi;
		if (vibor <= 21)//да коряво, зато работает 100%:  со switch пытался, выглядело еще хуже
		{
			if (vibor == 1)//используем ЦФ в соответствии с выбором в main
				yi = f1(xi);
			if (vibor == 2)
				yi = f2(xi);
			if (vibor == 3)
				yi = f3(xi);
			if (vibor == 4)
				yi = f4(xi);
			if (vibor == 5)
				yi = f5(xi);
			if (vibor == 6)
				yi = f6(xi);
			if (vibor == 7)
				yi = f7(xi);
			if (vibor == 8)
				yi = f8(xi);
			if (vibor == 9)
				yi = f9(xi);
			if (vibor == 10)
				yi = f10(xi);
			if (vibor == 11)
				yi = f11(xi);
			if (vibor == 12)
				yi = f12(xi);
			if (vibor == 13)
				yi = f13(xi);
			if (vibor == 14)
				yi = f14(xi);
			if (vibor == 15)
				yi = f15(xi);
			if (vibor == 16)
				yi = f16(xi);
			if (vibor == 17)
				yi = f17(xi);
			if (vibor == 18)
				yi = f18(xi);
			if (vibor == 19)
				yi = f19(xi);
			if (vibor == 20)
				yi = f20(xi);
			if (vibor == 21)
				yi = f21(xi);
		}
		else
			cout << "error - nedopustimiy nomer !!!!!!!" << endl;

		mas[i][1] = yi;
		Schet = Schet + 1;//счетчик вычислений функции для итогового отчета
		cout.precision(10);// выводит столько знаков сколько НАМ надо 
		//но самое интересное, что я нигде не встречал что cout выводит только стандартную длинну числа 
		//вне зависимости от типа этого числа. Столкнулся с этим впервые
		cout << "uzel= " << i << "  x= " << mas[i][0] << "  f(x)= " << mas[i][1] << endl;
	}

	double minY = mas[0][1];//по дефолту первый Y делаем минимальным.
	double minX = mas[0][0];
	double DoX = 0.0;
	double PosleX = 0.0;
	double DoY, PosleY;
	for (i = 0; i < newN; i++)//ищем минимальный Y 
	{
		if (mas[i][1] < minY) //если след меньше текущего
		{
			if (i < (newN - 1))//не конец
			{
				DoY = mas[i - 1][1];
				minY = mas[i][1];
				PosleY = mas[i + 1][1];

				DoX = mas[i - 1][0];//узел ДО найденной точ
				minX = mas[i][0];
				PosleX = mas[i + 1][0];//узел после точк
			}
			else//конец
			{
				DoY = mas[i - 1][1];
				minY = mas[i][1];
				PosleY = mas[i][1];

				DoX = mas[i - 1][0];
				minX = mas[i][0];
				PosleX = mas[i][0];
			}
		}
		else//  если след больше текущ
		{
			if (i == 0)//исключение для первого элем, котор изнач минимум
			{
				DoY = mas[i][1];
				minY = mas[i][1];
				PosleY = mas[i + 1][1];

				DoX = mas[i][0];
				minX = mas[i][0];
				PosleX = mas[i + 1][0];
			}
		}
	}
	cout.precision(10);// выводи столько знаков сколько НАМ надо 

	cout << endl << "  DoX =" << DoX << "  iskom X= " << minX << "  PosleX =" << PosleX << endl;
	cout << "  F(x)= " << minY << endl;
	cout << "  Ex = " << Ex << endl;
	cout << "  Ey = " << Ey << endl;

	//запоминаем последние 2 точки приближения + текущая
	//с получением новой точки, остальные смещаются , т.е считаем ВСЕГДА по последним 3 точкам приближения
	shod[2] = shod[1];
	shod[1] = shod[0];
	shod[0] = minX;

	double shodimost = abs((shod[1] - shod[0]) / (shod[2] - shod[1]));//коэфициент сходимости
	cout << " koefic shodimost = " << shodimost << endl;
	double raznica = abs(shod[1] - shod[0]);//сходимость
	cout << " shodimost na etom etape = " << raznica << endl;
	cout << " tochnost na etom etape po argumentu = " << ((PosleX - DoX) / 2) << endl;
	cout << " tochnost po znacheniy  = " << abs(PosleY - DoY) << endl;
	cout << endl << " proideno ciklov dlya poluchenia zadannoi tochnosti = " << k << endl << endl;

	if (abs(PosleX - DoX) / 2 >= Ex)//начинаем проверять аргумент 
	{
		ofstream obj("rezultat.txt", ios::binary | ios::app); //сразу выгружаем данные в конец файла без промежуточных массивов( как вариант)
		obj << " новая точка приближения №= " << k << "\r\n";
		obj << " min X = " << minX << "\r\n";
		obj << " F(x)= " << minY << "\r\n";
		obj << " точность на данном этапе по аргументу = " << (abs(PosleX - DoX) / 2) << "\r\n";
		obj << " точность на данном этапе по значению = " << abs(PosleY - DoY) << "\r\n";
		obj << " сходимость на этом этапе = " << raznica << "\r\n";
		obj << "цикл программы = " << k << "\r\n";
		obj << "\r\n";
		obj.close();
		k = k + 1;
		RavnPoisk(vibor, N, DoX, PosleX, Ex, Ey, k, shod, Schet);
	}
	else// точн по аргументу стала меньше заданной точности
	{
		if (abs(PosleY - DoY) >= Ey)//начинаем проверять по значению
		{
			ofstream obj("rezultat.txt", ios::binary | ios::app); //сразу выгружаем данные в конец файла без промежуточных массивов( как вариант)
			obj << " новая точка приближения №= " << k << "\r\n";
			obj << " min X = " << minX << "\r\n";
			obj << " F(x)= " << minY << "\r\n";
			obj << " точность на данном этапе по аргументу = " << (abs(PosleX - DoX) / 2) << "\r\n";
			obj << " точность на данном этапе по значению = " << abs(PosleY - DoY) << "\r\n";
			obj << " сходимость на этом этапе = " << raznica << "\r\n";
			obj << "цикл программы = " << k << "\r\n";
			obj << "\r\n";
			obj.close();
			k = k + 1;
			RavnPoisk(vibor, N, DoX, PosleX, Ex, Ey, k, shod, Schet);
		}
		else//точность по аргум и значению меньше заданных
		{
			ofstream obj("rezultat.txt", ios::binary | ios::app); //финальная запись с данными
			obj << " последняя точка приближения №= " << k << "\r\n";
			obj << " min X = " << minX << "\r\n";
			obj << " F(x)= " << minY << "\r\n";
			obj << " точность на данном этапе по аргументу = " << (abs(PosleX - DoX) / 2) << "\r\n";
			obj << " точность на данном этапе по значению = " << abs(PosleY - DoY) << "\r\n";
			obj << " сходимость на этом этапе = " << raznica << "\r\n";
			obj << "цикл программы =" << k << "\r\n";

			obj << "\r\n";
			obj << " наидено точек приближения = " << k << "\r\n";
			obj << " количество интервалов на каждом этапе = " << N << "\r\n";
			obj << " исходная Ex = " << Ex << "\r\n";
			obj << " исходная Ey = " << Ey << "\r\n";
			if (k >= 3)//если точек меньше, то не получися корректно вычислить по формуле
			{
				obj << " коэфициент сходимости по последним 3 точкам = " << shodimost << "\r\n";
			}
			else
				obj << " недостаточно точек для вычисления коэффициента сходимости " << "\r\n";
			obj << "циклов программы всего проидено = " << k << "\r\n";//с учетом нулевого цикла
			obj << " общее количество вычислений функции = " << Schet << "\r\n";
			obj.close();
			return 0;
		}
	}

	for (i = 0; i < newN; i++)
		delete[] mas[i];
	delete[] mas;
}

int main()
{
	int vibor, N;
	double a, b, Ex, Ey;

	cout << "1  y = sqrt(1 + (pow(x, 2))) + exp(-2 * x)  //0,1" << endl <<
		"2  y = pow(x, 4) + 2 * (pow(x, 2)) + 4 * x + 1  //-1,0" << endl <<
		"3  y = pow(x, 4) - 10 * (pow(x, 3)) + 36 * (pow(x, 2)) + 5 * x  //3,5" << endl <<
		"4  y = pow(x, 4) + 2 * (pow(x, 2)) + 4 * x + 1  //3,5" << endl <<
		"5  y = log(1 + (pow(x, 2))) - sin(x)  //0,45" << endl <<
		"6  y = 0.25 *(pow(x, 4)) + pow(x, 2) - 8 * x + 12  //0,2" << endl <<
		"7  y = pow(x, 3) - x + 1  //-2,0" << endl <<
		"8  y = 2* (pow(x, 2)) + 16 / x  //1,5" << endl <<
		"9  y = 4 + (pow(x, 3)) + 2 * x - 3 * (pow(x, 2)) + exp(x / 2)  //-5,0" << endl <<
		"10 y = 12 * (pow(x, 2)) - (2 / 3) *(pow(x, 3))  //5,20" << endl <<
		"11 y = pow(x, 4) - 12 * (pow(x, 3)) + 47 * (pow(x, 2)) - 60 * x  //-1, 2.5" << endl <<
		"12 y = 10 * (pow(x, 3)) + 3 * (pow(x, 2)) + x + 5  //1,5" << endl <<
		"13 y = pow(x, 4) + 2 * (pow(x, 2)) + 4 * x + 1  //-1,0" << endl <<
		"14 y = pow(x, 2) + exp(-x)  //5,10" << endl <<
		"15 y = 2 * x + exp(-x)  //-4,4" << endl <<
		"16 y = pow(x, 2) + x + sin(x)  //-10,10" << endl <<
		"17 y = pow(x, 2) - x + exp(-x)  //-3,10" << endl <<
		"18 y = 2 * (pow(x, 2)) - 5 - pow(2,x)  //4,6" << endl <<
		"19 y = (1 / 3) * (pow(x, 3)) + 2 * (pow(x, 2)) - 5 * x + 6  //-3,5" << endl <<
		"20 y = -pow(x, 2) + 5 * x - 6  //-5,10" << endl <<
		"21 y = abs((abs(x*(x - 1))) - 1)  //-3,0" << endl << endl;

	cout << " viberite nomer yravneniya iz spiska " << endl;
	cin >> vibor;
	cout << " vvedite kollich uzlov" << endl;
	cin >> N;
	cout << " vvedite nachalo otrezka" << endl;
	cin >> a;
	cout << " vvedite konec otrezka" << endl;
	cin >> b;
	cout << " vvedite tochnost Ex" << endl;
	cin >> Ex;
	cout << " vvedite tochnost Ey" << endl;
	cin >> Ey;

	double shod[] = { 0,0,0 };//массив на 2 элем для записи 2 точек приближения и вычисления сходимости(3 элемент для конечной точки)
	int Schet = 0;
	ofstream obj("rezultat.txt");// обнуляем файл для записи,если он уже был создан на предыдущем сеансе
	RavnPoisk(vibor, N, a, b, Ex, Ey, 1, shod, Schet);//номер уравнения в функцию
	system("pause");
}