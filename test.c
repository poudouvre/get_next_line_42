
int	next_line(char *line)
{
	int	len;
	char *stock;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;

	if (line[len] == '\n')
	{
		line = ft_substr(line, 0, len);
		// stock is from len + 1 until next \n or \0 or BUFF_SIZE ???
		 

}
