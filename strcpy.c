//#include<stdio.h>
//#include<assert.h>
//void *my_memmove(void *dest, const void *src, size_t count)
//{
//	void *ret = dest;
//	assert(dest && src);
//	if (dest <= src || (char*)dest >= (char*)src + count)
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//void *my_memcpy(void *dest, const void *src, size_t count)
//{
//	void *ret = dest;
//	assert(dest && src);
//	while (count--)
//	{
//		*(char *)dest = *(char *)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdefghi";
//	my_memmove(arr1+3,arr1,4);
//	my_memcpy(str + 2, str, 5);
//	printf("%s\n", arr1 + 3);
//	printf("%s\n", str + 2);
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char *src, const char *dest)
//{
//	assert(src && dest);
//	while (!(*(unsigned char *)src - *(unsigned char *)dest) && *dest)
//	{
//		++src;
//		++dest;
//	}
//	return *src - *dest;
//}
//int main()
//{
//	int ret = 0;
//	char str1[] = "abddef";
//	char str2[] = "abcdef";
//	ret =(int) my_strcmp(str1, str2);
//	if (ret > 0)
//		ret = 1;
//	else if (ret < 0)
//		ret = -1;
//	printf("%d\n", ret);
//	return 0;
//}

#include<stdio.h>
#include<assert.h>
int main()
{

	return 0;
}








