//#include<stdio.h>
//#include<graphics.h>
//#include<conio.h>
//struct Ball
//{
//	int x;
//	int y;
//	int r;
//	int dx;
//	int dy;
//};
//struct Ball ball = { 400,400,15,5,-4};
//void DrawBall(struct Ball ball)
//{
//	setfillcolor(RED);
//	solidcircle(ball.x, ball.y, ball.r);
//}
//void MoveBall()
//{
//	if (ball.x - ball.r <= 0 || ball.x + ball.r >= 800)
//	{
//		ball.dx = -ball.dx;
//	}
//	if (ball.y - ball.r <= 0 || ball.y + ball.r >= 800)
//	{
//		ball.dy = -ball.dy;
//	}
//	ball.x += ball.dx;
//	ball.y -= ball.dy;
//}
//
//struct Ball myball = {500,500,15,5,5};
////void Draw()
////{
////	initgraph(400, 400);
////	setbkcolor(LIGHTBLUE);
////	cleardevice();
////	setlinecolor(BLACK);
////	for (int i = 0; i <= 400; i += 20)
////	{
////		line(0, i, 400, i);
////		line(i, 0, i, 400);
////	}
////	while (1);
////	closegraph();
////}
//void KeyDown()
//{
//	int userKey = _getch();
//	switch (userKey)
//	{
//	case'w':
//	case'W':
//	case 72:
//		myball.y -= 5;
//		break;
//	case's':
//	case'S':
//	case 80:
//		myball.y += 5;
//		break;
//	case'a':
//	case'A':
//	case 75:
//		myball.x -= 5;
//		break;
//	case'd':
//	case'D':
//	case 77:
//		myball.x += 5;
//		break;
//	}
//}
//int main()
//{
//	//Draw();
//	/*initgraph(600, 800);
//	setbkcolor(RED);
//	cleardevice();
//	line(0, 0, 800, 600);
//	circle(100, 100, 50);
//	rectangle(300, 300, 400, 400);
//	setfillcolor(LIGHTBLUE);
//	fillcircle(200, 300, 50);
//	solidcircle(300, 300, 50);
//	fillrectangle(400, 400, 500, 500);
//	solidrectangle(10, 10, 100, 100);
//	getchar();
//	closegraph();*/
//
//	//initgraph(800, 600);
//	//int a = 1;
//	//IMAGE img;
//	//loadimage(&img, "./Res/ÒøÀÇ.jpg",800,600);
//	//putimage(0, 0, &img);
//	//while (1);
//	//closegraph();
//	initgraph(800, 800);
//	while (1)
//	{
//		cleardevice();
//		DrawBall(ball);
//		DrawBall(myball);
//		MoveBall();
//		if (_kbhit())
//		{
//			KeyDown();
//		}
//		Sleep(20);
//	}
//	closegraph();
//	return 0;
//}