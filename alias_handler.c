#include "shell.h"

/**
 * print_alias - handle alias
 * @data: program data struct
 * @alias: name of the alias
 * Return: 0 on success, number declared in the args
 *
 * This function prints the value of the specified alias. It searches for the
 * alias in the alias list stored in the program data struct. If the alias is
 * found, it prints the alias name and its corresponding value. If no alias is
 * specified, it prints all the aliases in the alias list.
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - handle alias
 * @data: program's data struct
 * @name: name of the requested alias
 * Return: 0 on success, number declared in the args, NULL if not found
 *
 * This function retrieves the value of the specified alias. It searches for
 * the alias in the alias list stored in the program data struct. If the alias
 * is found, it returns the value of the alias. If the alias is not found, it
 * returns NULL.
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* check if varname exist in env */
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{/* returns the value of the key NAME=  when find it */
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	return (NULL);

}


/**
 * set_alias - creates alias, overrides if exists
 * @alias_string: alias to be set
 * @data: program data struct
 * Return: 0 on success, number declared in args
 *
 * This function sets the value of the specified alias. It creates a new alias
 * if the alias does not already exist, or overrides the existing alias if it
 * does exist. The alias is stored in the alias list in the program data struct.
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{/* check if value of the alias already exists in another alias */
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	/* check if varname exist in the alias list */
	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{/* if the alias alredy exist */
			free(data->alias_list[j]);
			break;
		}

	/* add alias */
	if (temp)
	{/* override existing alias */
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}
