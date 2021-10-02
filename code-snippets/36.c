// CVE - 2020 - 15780
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define LOCKDOWN_ACPI_TABLES "modifying ACPI tables"

// Hook that returns a value
int call_int_hook(int IRC, char *reason)
{
    int RC = IRC;
    printf("Check for security hooks\n");
    return RC;
}

int security_locked_down()
{
    printf("Hello world\n");
    return call_int_hook(1, LOCKDOWN_ACPI_TABLES);
}

int acpi_table_aml_write()
{
    // Unchecked security before loading table
    int ret;

    // Malocious tables can be loaded
    ret = acpi_load_table();
    return ret;
}

int acpi_load_table()
{
    printf("Acpi load table method called\n");
    return 5;
}

int main()
{
    int rv = acpi_table_aml_write();
    return 0;
}