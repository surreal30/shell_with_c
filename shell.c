#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * read_line()
{
	int buffsize = 1024;
	int position = 0;
	char * buffer = malloc(sizeof(char) * buffsize);
	int c;

	if(!buffer)
	{
		fprintf(stderr, "%sdash: Allocation error%s\n", RED, RESET);
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		c = getchar();
		if( c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if(position >= buffsize)
		{
			buffsize += 1024;
			buffer = realloc(buffer, buffsize);

			if(!buffer)
			{
				fprintf(stderr, "dash: Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

void loop()
{
	char * line;
	char * * args;
	int status = 1;

	do
	{
		printf("> ");
		line = read_line();
		flag = 0;
		args = split_lines(line);
		status = dash_launch(args);
		free(line);
		free(args);
	} while (status);
}