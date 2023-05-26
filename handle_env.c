#include "shell.h"

/**
 * env_get_key - get value of env var
 * @key: env var
 * @data: program data struct
 * Return: ptr to value of var or NULL
 */
char *env_get_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			return (data->env[i] + key_length + 1);
		}
	}
	return (NULL);
}

/**
 * env_set_key - overwrite env var or create
 * @key: name of the var
 * @value: new value
 * @data: program data struct
 * Return: 1 if pars are NULL, 2 on error, 0 on sucess.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			is_new_key = 0;

			free(data->env[i]);
			break;
		}
	}
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);

	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - remove key from env
 * @key: the key to remove
 * @data: program data struct
 * Return: 1 if the key removed, 0 if the key does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			free(data->env[i]);

			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - print current env
 * @data: program data struct
 * Return: void
 */
void print_environ(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
