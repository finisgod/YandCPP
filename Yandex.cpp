#include <stdlib.h>
#include <stdio.h>
#include <iostream> 
#include <fstream> 
#include <string> 
#include <ctime> 
#include "windows.h"

const int M = 12;
const int N = 10;
using namespace std;
int timer = 0;
int stopper = 0;

int main(int argc , char* argv[])
{
	
	    
	    	
	srand(time(0));

	int a[M][N];
	
	int count = 0;
	
	
	int status[M][N] ;
	{
		for (int q = 0; q < M; q++)
		{

			for (int e = 0; e < N; e++)
			{
				status[q][e]=0 ;
			}

			cout << endl;
		}

		cout << endl;
	}
	//âûâîä ñîñòîÿíèÿ 
	
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				a[i][j] = ((int)rand() % 2);
			}
		}
	}

	

	cout << "Start" << endl << endl;

	for (int q = 0; q < M; q++)
	{
		for (int e = 0; e < N; e++)
		{
			cout << a[q][e];
		}
		cout << endl;
	}



	//check



	for (int cikl = 0; cikl > -1; cikl++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{

				
				if (i == 0 && j != 0 && j != N - 1)
					for (int k = 0; k < 2; k++)
					{
						for (int l = j - 1; l < j + 2; l++)
						{
							if (a[k][l] == 1)
								count++;
						}
					}

				
				else
					if (i == M - 1 && j != 0 && j != N - 1)
						for (int k = M - 2; k < M; k++)
						{
							for (int l = j - 1; l < j + 2; l++)
							{
								if (a[k][l] == 1)
									count++;
							}
						}

				
					else
						if (j == 0 && i != 0 && i != M - 1)
							for (int k = i - 1; k < i + 2; k++)
							{
								for (int l = 0; l < 2; l++)
								{
									if (a[k][l] == 1)
										count++;
								}
							}

				
						else
							if (j == N - 1 && i != 0 && i != M - 1)
								for (int k = i - 1; k < i + 2; k++)
								{
									for (int l = N - 2; l < N; l++)
									{
										if (a[k][l] == 1)
											count++;
									}
								}

				
							else
								if (j == 0 && i == 0)
									for (int k = 0; k < 2; k++)
									{
										for (int l = 0; l < 2; l++)
										{
											if (a[k][l] == 1)
												count++;
										}
									}

				
								else
									if (j == 0 && i == M - 1)
										for (int k = M - 2; k < M; k++)
										{
											for (int l = 0; l < 2; l++)
											{
												if (a[k][l] == 1)
													count++;
											}

										}

				
									else
										if (j == N - 1 && i == 0)
											for (int k = 0; k < 2; k++)
											{
												for (int l = N - 2; l < N; l++)
												{
													if (a[k][l] == 1)
														count++;
												}
											}

				
										else
											if (j == N - 1 && i == M - 1)
												for (int k = M - 2; k < M; k++)
												{
													for (int l = N - 2; l < N; l++)
													{
														if (a[k][l] == 1)
															count++;
													}
												}

				/////////////////////////////////////

											else
												for (int k = i - 1; k < i + 2; k++)
												{
													for (int l = j - 1; l < j + 2; l++)
													{
														if (a[k][l] == 1)
															count++;
													}
												}

				if (a[i][j] == 1)
					count--;
				
				status[i][j] = a[i][j];
				if (count < 2)
					status[i][j] = 0;
				if (count > 3)
					status[i][j] = 0;
				if (count == 3)
					status[i][j] = 1;

				count = 0;
			}

		}

		cout << endl;

		
		timer++;
		cout << endl << "Timer :  " << timer << " sec" << endl << endl;

		


			for (int q = 0; q < M; q++)
			{

				for (int e = 0; e < N; e++)
				{
					cout << status[q][e];
				}

				cout << endl;
			}

			cout << endl;
		
		
		
			for (int q = 0; q < M; q++)
			{
				for (int e = 0; e < N; e++)
				{
					if (a[q][e] == status[q][e])
						stopper++;
					else
					{
						stopper = 0;
						break;
					}
				}
				if (stopper == 0)
				break;
			}

			if (stopper != 0)
			{
				cout << endl << "The end  :) ";
				break;
			}

			stopper = 0;
		
		
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					a[i][j] = status[i][j];
				}
			}
		}
		
		Sleep(1000);

	}

	system("pause");
	
	return 0;

}

