#include<graphics.h>
int main()
{
	initgraph(800, 800);
	ExMessage msg;
	while (1)
	{
		while (peekmessage(&msg))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				circle(msg.x, msg.y, 10);
				break;
			case WM_RBUTTONDOWN:
				rectangle(msg.x - 5, msg.y - 5, msg.x + 5, msg.y + 5);
				break;
			}
		}
	}
}