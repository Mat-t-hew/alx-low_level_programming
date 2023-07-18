#include "100-elf_header.h"
#include <elf.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

/**
 * print_error - Prints an error message and exits.
 * @message: The error message to be printed.
 */

void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */

void print_magic(const unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < 16; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void print_class(const unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[4])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case 1:
			printf("ELF32\n");
			break;
		case 2:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void print_data(const unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[5])
	{
		case 1:
			printf("2's complement, little endian\n");
			break;
		case 2:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */

void print_version(const unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);
}

/**
 * print_os_abi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */

void print_os_abi(const unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}

/**
 * print_abi_version - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi_version(const unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);

}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 */

void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("No file type\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;

		default:
			printf("Unknown\n");
			break;
	}
}

/**
 * print_entry_point - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 */

void print_entry_point(uint64_t e_entry)
{
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
	printf("  Entry point address: 0x%llx\n", (unsigned long long)e_entry);
#else
	printf("  Entry point address: 0x%lx\n", (unsigned long)e_entry);
#endif
}

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @file_name: The name of the ELF file.
 */

void print_elf_header(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	unsigned char e_ident[ELF_HEADER_SIZE];
	ssize_t ret = read(fd, e_ident, ELF_HEADER_SIZE);
	Elf64_Ehdr *header = (Elf64_Ehdr *)e_ident;

	if (fd == -1)
		print_error("Unable to open the file");

	if (ret != ELF_HEADER_SIZE)
		print_error("Unable to read the ELF header");

	close(fd);

	printf("ELF Header:\n");
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_os_abi(e_ident);
	print_abi_version(e_ident);

	print_type(header->e_type);
	print_entry_point(header->e_entry);
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	const char *file_name = argv[1];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	print_elf_header(file_name);
	return (0);
}

