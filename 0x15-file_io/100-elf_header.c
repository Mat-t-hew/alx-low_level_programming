#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
/**
 *read_textfile-R t f p t S
 *print_error-t f b r
 *print_elf_header-ttt
 *main-ttttt
 *Return: 0
 */

#define ELF_HEADER_SIZE 64

void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

void print_elf_header(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);

	if (fd == -1)
		print_error("Unable to open the file");

	Elf64_Ehdr header;
	ssize_t ret = read(fd, &header, sizeof(Elf64_Ehdr));

	if (ret != sizeof(Elf64_Ehdr))
		print_error("Unable to read the ELF header");

	close(fd);

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < sizeof(header.e_ident); i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");

	printf("  Class:                             ");
	switch (header.e_ident[4])
	{
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

	printf("  Data:                              ");
	switch (header.e_ident[5])
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

	printf("  Version:                      %d (current)\n", header.e_ident[6]);

	printf("  OS/ABI:                            ");
	switch (header.e_ident[7])
	{
	case 0:
		printf("UNIX System V ABI\n");
		break;
	case 1:
		printf("HP-UX ABI\n");
		break;
	case 2:
		printf("NetBSD ABI\n");
		break;
	case 3:
		printf("Linux ABI\n");
		break;
	case 6:
		printf("Sun Solaris ABI\n");
		break;
	case 7:
		printf("IBM AIX ABI\n");
		break;
	case 8:
		printf("SGI IRIX ABI\n");
		break;
	case 9:
		printf("FreeBSD ABI\n");
		break;
	case 10:
		printf("Compaq TRU64 UNIX ABI\n");
		break;
	case 11:
		printf("Novell Modesto ABI\n");
		break;
	case 12:
		printf("OpenBSD ABI\n");
		break;
		default:
			printf("Unknown\n");
			break;
	}

	printf("  ABI Version:                       %d\n", header.e_ident[8]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
	case 0:
		printf("No file type\n");
		break;
	case 1:
		printf("Relocatable file\n");
		break;
	case 2:
		printf("Executable file\n");
		break;
	case 3:
		printf("Shared object file\n");
		break;
	case 4:
		printf("Core file\n");
		break;
		default:
			printf("Unknown\n");
			break;
	}

	printf("  Entry point address: 0x%llx\n", (unsigned long long)header.e_entry);

	printf("  Format:                            ELF64\n");
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	const char *file_name = argv[1];

	print_elf_header(file_name);

	return (0);
}
