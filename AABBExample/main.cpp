#include <stdio.h>
#include <Windows.h>

struct boundingBox 
{
	int x;
	int y;
	int height;
	int width;
	int vx;
	int vy;
};
// prototype for isColliding function

int isColliding(struct boundingBox box1, struct boundingBox box2);
float getTime();
void Update(float dt);

int main()
{
	struct boundingBox bb1;
	struct boundingBox bb2;
	bb1.x = 0;
	bb1.y = 0;
	bb1.height = 10;
	bb1.width = 10;
	bb2.x = 5;
	bb2.y  = 5;
	bb2.height = 10;
	bb2.width = 10;

	if(isColliding(bb1,bb2) == 1)
	{
		printf("Boxes are colliding \n");
	} else {
		printf("Boxes are not colliding \n");
	}
	
	// game loop implementation
	float previousTime = 0;
	float currentTime = 0;
	while(true)
	{
		previousTime = currentTime;
		currentTime = getTime();
		float dt = currentTime - previousTime;
		// is dt gets to big
		if(dt > 0.15f)
		{
			dt = 0.15f;
			printf("%f set it back \n", dt);
		}
		Update(dt);
	}
	return 0;
}
void Update(float dt)
{
	// do our update here
}
float getTime()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	float theCurrentTimeInSeconds = st.wSecond;
	return theCurrentTimeInSeconds;
}
int isColliding(struct boundingBox box1, struct boundingBox box2)
{
	if(!((box1.x + box1.width) >= box2.x))
	{
		return 0;
	}
	if(!(box1.x <= (box2.x + box2.width)))
	{
		return 0;
	}
	if(!((box1.y - box1.height) <= box2.y))
	{
		return 0;
	}
	if(!(box1.y >= (box2.y - box2.height)))
	{
		return 0;
	}
	return 1;
}