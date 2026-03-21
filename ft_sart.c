float	ft_sqrt(int number)
{
	double	i;
	
	i = 0.01;
	while (i * i <= number)
	{
		if (i * i == number)
			return(i);
		i = i + 0.01;
	}
	return (i);
}

