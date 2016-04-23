

int Front = -1, Rear = -1, MaxSize = 0;

void InitializeQ (int Max)
{
	Front = -1;
	Rear = -1;
	MaxSize = Max;
}

int IsEmptyQ ()
{
	if (Front == -1)
		return 1;
	return 0;
}

int IsFullQ ()
{
	if (Front == (Rear + 1) % MaxSize)
		return 1;
	return 0;
}

void Enqueue (vertex **Q, vertex *V)
{
	if (Q == NULL)
	{
        return;

	}

	if (Front == -1)
	{
		Front += 1;
	}

	else if ((Rear + 1) % MaxSize == Front)
	{
		// Full

            return;
	}

	Rear = (Rear + 1) % MaxSize;
	Q[Rear] = V;
}

vertex* Dequeue (vertex** Q)
{
	int Temp;

	if (Front == -1)
		return NULL;

	if (Rear == 0 && Front != 0)
	{
		Rear = MaxSize - 1;
		return Q[Rear + 1];
	}

	if (Front == Rear)
	{
		Front = -1;
		Temp = Rear;
		Rear = -1;
		return Q[Temp];
	}

	return Q[Rear--];
}
