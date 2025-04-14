AUTOMAKE_OPTIONS = foreign subdir-objects

includedir = $(prefix)/include
include_HEADERS = include/tinydns_client.h include/tinydns_common.h
dist_include_HEADERS = $(include_HEADERS)

AM_CPPFLAGS = -I$(top_srcdir)/include  -I$(top_srcdir)/test -ansi
check_PROGRAMS = \
    test/tinydns_test_client_resource_records

test_tinydns_test_client_resource_records_SOURCES = test/client_resource_records.c

TESTS = $(check_PROGRAMS)