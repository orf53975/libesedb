/*
 * Debug functions
 *
 * Copyright (c) 2009-2011, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#include <liberror.h>
#include <libnotify.h>

#include "libesedb_debug.h"
#include "libesedb_definitions.h"
#include "libesedb_libbfio.h"

#if defined( HAVE_DEBUG_OUTPUT )

/* Prints the file type
 */
void libesedb_debug_print_file_type(
      uint32_t file_type )
{
	switch( file_type )
	{
		case LIBESEDB_FILE_TYPE_DATABASE:
			libnotify_printf(
			 "Database" );
			break;

		case LIBESEDB_FILE_TYPE_STREAMING_FILE:
			libnotify_printf(
			 "Streaming file" );
			break;

		default:
			libnotify_printf(
			 "(Unknown)" );
	}
}

/* Prints the database state
 */
void libesedb_debug_print_database_state(
      uint32_t database_state )
{
	switch( database_state )
	{
		case 1:
			libnotify_printf(
			 "Just created (JET_dbstateJustCreated)" );
			break;

		case 2:
			libnotify_printf(
			 "Dirty Shutdown (JET_dbstateDirtyShutdown)" );
			break;

		case 3:
			libnotify_printf(
			 "Clean Shutdown (JET_dbstateCleanShutdown)" );
			break;

		case 4:
			libnotify_printf(
			 "Being converted (JET_dbstateBeingConverted)" );
			break;

		case 5:
			libnotify_printf(
			 "Force Detach (JET_dbstateForceDetach)" );
			break;

		default:
			libnotify_printf(
			 "(Unknown)" );
			break;
	}
}

/* Prints the page flags
 */
void libesedb_debug_print_page_flags(
      uint32_t page_flags )
{
	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_ROOT ) != 0 )
	{
		libnotify_printf(
		 "\tIs root\n" );
	}
	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_LEAF ) != 0 )
	{
		libnotify_printf(
		 "\tIs leaf\n" );
	}
	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_PARENT ) != 0 )
	{
		libnotify_printf(
		 "\tIs parent\n" );
	}
	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_EMPTY ) != 0 )
	{
		libnotify_printf(
		 "\tIs empty\n" );
	}

	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_SPACE_TREE ) != 0 )
	{
		libnotify_printf(
		 "\tIs space tree\n" );
	}
	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_INDEX ) != 0 )
	{
		libnotify_printf(
		 "\tIs index\n" );
	}
	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_LONG_VALUE ) != 0 )
	{
		libnotify_printf(
		 "\tIs long value\n" );
	}

	if( ( page_flags & LIBESEDB_PAGE_FLAG_0x0400 ) != 0 )
	{
		libnotify_printf(
		 "\t0x0400\n" );
	}
	if( ( page_flags & LIBESEDB_PAGE_FLAG_0x0800 ) != 0 )
	{
		libnotify_printf(
		 "\t0x0800 (primary?)\n" );
	}

	if( ( page_flags & LIBESEDB_PAGE_FLAG_IS_NEW_RECORD_FORMAT ) != 0 )
	{
		libnotify_printf(
		 "\tIs new record format\n" );
	}
}

/* Prints the page tag flags
 */
void libesedb_debug_print_page_tag_flags(
      uint8_t page_tag_flags )
{
	if( page_tag_flags > 0 )
	{
		libnotify_printf(
		 " (" );

		if( ( page_tag_flags & 0x04 ) != 0 )
		{
			libnotify_printf(
			 "c" );
		}
		if( ( page_tag_flags & 0x02 ) != 0 )
		{
			libnotify_printf(
			 "d" );
		}
		if( ( page_tag_flags & 0x01 ) != 0 )
		{
			libnotify_printf(
			 "v" );
		}
		libnotify_printf(
		 ")" );
	}
}

/* Prints the tagged data type flags
 */
void libesedb_debug_print_tagged_data_type_flags(
      uint8_t tagged_data_type_flags )
{
	if( ( tagged_data_type_flags & LIBESEDB_VALUE_FLAG_VARIABLE_SIZE ) != 0 )
	{
		libnotify_printf(
		 "\tIs variable size\n" );
	}
	if( ( tagged_data_type_flags & LIBESEDB_VALUE_FLAG_COMPRESSED ) != 0 )
	{
		libnotify_printf(
		 "\tIs compressed\n" );
	}
	if( ( tagged_data_type_flags & LIBESEDB_VALUE_FLAG_LONG_VALUE ) != 0 )
	{
		libnotify_printf(
		 "\tIs long value\n" );
	}
	if( ( tagged_data_type_flags & LIBESEDB_VALUE_FLAG_MULTI_VALUE ) != 0 )
	{
		libnotify_printf(
		 "\tIs multi value\n" );
	}
}

/* Prints the data definition type
 */
void libesedb_debug_print_page_value_definition_type(
      uint16_t page_value_definition_type )
{
	switch( page_value_definition_type )
	{
		case 1:
			libnotify_printf(
			 "(Table)" );
			break;

		case 2:
			libnotify_printf(
			 "(Column)" );
			break;

		case 3:
			libnotify_printf(
			 "(Index)" );
			break;

		case 4:
			libnotify_printf(
			 "(Long Value)" );
			break;

		case 5:
			libnotify_printf(
			 "(Callback)" );
			break;

		default:
			libnotify_printf(
			 "(Unknown)" );
			break;
	}
}

/* Prints the table group of bits
 */
void libesedb_debug_print_table_group_of_bits(
      uint32_t table_group_of_bits )
{
	if( ( table_group_of_bits & 0x00000001 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitTableCreateFixedDDL)\n" );
	}
	if( ( table_group_of_bits & 0x00000002 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitTableCreateTemplateTable)\n" );
	}
	if( ( table_group_of_bits & 0x00000004 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitTableCreateNoFixedVarColumnsInDerivedTables)\n" );
	}
}

/* Prints the column group of bits
 */
void libesedb_debug_print_column_group_of_bits(
      uint32_t column_group_of_bits )
{
	if( ( column_group_of_bits & 0x00000001 ) != 0 )
	{
		libnotify_printf(
		 "\tIs fixed size (JET_bitColumnFixed)\n" );
	}
	if( ( column_group_of_bits & 0x00000002 ) != 0 )
	{
		libnotify_printf(
		 "\tIs tagged (JET_bitColumnTagged)\n" );
	}
	if( ( column_group_of_bits & 0x00000004 ) != 0 )
	{
		libnotify_printf(
		 "\tNot empty (JET_bitColumnNotNULL)\n" );
	}
	if( ( column_group_of_bits & 0x00000008 ) != 0 )
	{
		libnotify_printf(
		 "\tIs version column (JET_bitColumnVersion)\n" );
	}
	if( ( column_group_of_bits & 0x00000010 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnAutoincrement)\n" );
	}
	if( ( column_group_of_bits & 0x00000020 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnUpdatable)\n" );
	}
	if( ( column_group_of_bits & 0x00000040 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnTTKey)\n" );
	}
	if( ( column_group_of_bits & 0x00000080 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnTTDescending)\n" );
	}

	if( ( column_group_of_bits & 0x00000400 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnMultiValued)\n" );
	}
	if( ( column_group_of_bits & 0x00000800 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnEscrowUpdate)\n" );
	}
	if( ( column_group_of_bits & 0x00001000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnUnversioned)\n" );
	}
	if( ( column_group_of_bits & 0x00002000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnDeleteOnZero or JET_bitColumnMaybeNull)\n" );
	}
	if( ( column_group_of_bits & 0x00004000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnFinalize)\n" );
	}
	if( ( column_group_of_bits & 0x00008000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitColumnUserDefinedDefault)\n" );
	}
}

/* Prints the index group of bits
 */
void libesedb_debug_print_index_group_of_bits(
      uint32_t index_group_of_bits )
{
	if( ( index_group_of_bits & 0x00000001 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexUnique)\n" );
	}
	if( ( index_group_of_bits & 0x00000002 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexPrimary)\n" );
	}
	if( ( index_group_of_bits & 0x00000004 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexDisallowNull)\n" );
	}
	if( ( index_group_of_bits & 0x00000008 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexIgnoreNull)\n" );
	}
	if( ( index_group_of_bits & 0x00000010 ) != 0 )
	{
		libnotify_printf(
		 "\t(0x00000010)\n" );
	}
	if( ( index_group_of_bits & 0x00000020 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexIgnoreAnyNull)\n" );
	}
	if( ( index_group_of_bits & 0x00000040 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexIgnoreFirstNull)\n" );
	}
	if( ( index_group_of_bits & 0x00000080 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexLazyFlush)\n" );
	}
	if( ( index_group_of_bits & 0x00000100 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexEmpty)\n" );
	}
	if( ( index_group_of_bits & 0x00000200 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexUnversioned)\n" );
	}
	if( ( index_group_of_bits & 0x00000400 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexSortNullsHigh)\n" );
	}
	if( ( index_group_of_bits & 0x00000800 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexUnicode)\n" );
	}
	if( ( index_group_of_bits & 0x00001000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexTuples)\n" );
	}
	if( ( index_group_of_bits & 0x00002000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexTupleLimits)\n" );
	}
	if( ( index_group_of_bits & 0x00004000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexCrossProduct)\n" );
	}
	if( ( index_group_of_bits & 0x00008000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexKeyMost)\n" );
	}
	if( ( index_group_of_bits & 0x00010000 ) != 0 )
	{
		libnotify_printf(
		 "\t(JET_bitIndexDisallowTruncation)\n" );
	}
}

/* Prints the file attribute flags
 * Returns 1 if successful or -1 on error
 */
void libesedb_debug_print_file_attribute_flags(
      uint32_t file_attribute_flags )
{
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_READ_ONLY ) != 0 )
	{
		libnotify_printf(
		 "\tIs read-only (FILE_ATTRIBUTE_READ_ONLY)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_HIDDEN ) != 0 )
	{
		libnotify_printf(
		 "\tIs hidden (FILE_ATTRIBUTE_HIDDEN)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_SYSTEM ) != 0 )
	{
		libnotify_printf(
		 "\tIs system (FILE_ATTRIBUTE_SYSTEM)\n" );
	}

	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_DIRECTORY ) != 0 )
	{
		libnotify_printf(
		 "\tIs directory (FILE_ATTRIBUTE_DIRECTORY)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_ARCHIVE ) != 0 )
	{
		libnotify_printf(
		 "\tShould be archived (FILE_ATTRIBUTE_ARCHIVE)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_DEVICE ) != 0 )
	{
		libnotify_printf(
		 "\tIs device (FILE_ATTRIBUTE_DEVICE)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_NORMAL ) != 0 )
	{
		libnotify_printf(
		 "\tIs normal (FILE_ATTRIBUTE_NORMAL)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_TEMPORARY ) != 0 )
	{
		libnotify_printf(
		 "\tIs temporary (FILE_ATTRIBUTE_TEMPORARY)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_SPARSE_FILE ) != 0 )
	{
		libnotify_printf(
		 "\tIs a sparse file (FILE_ATTRIBUTE_SPARSE_FILE)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_REPARSE_POINT ) != 0 )
	{
		libnotify_printf(
		 "\tIs a reparse point or symbolic link (FILE_ATTRIBUTE_FLAG_REPARSE_POINT)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_COMPRESSED ) != 0 )
	{
		libnotify_printf(
		 "\tIs compressed (FILE_ATTRIBUTE_COMPRESSED)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_OFFLINE ) != 0 )
	{
		libnotify_printf(
		 "\tIs offline (FILE_ATTRIBUTE_OFFLINE)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_NOT_CONTENT_INDEXED ) != 0 )
	{
		libnotify_printf(
		 "\tContent should not be indexed (FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)\n" );
	}
	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_ENCRYPTED ) != 0 )
	{
		libnotify_printf(
		 "\tIs encrypted (FILE_ATTRIBUTE_ENCRYPTED)\n" );
	}

	if( ( file_attribute_flags & LIBESEDB_FILE_ATTRIBUTE_FLAG_VIRTUAL ) != 0 )
	{
		libnotify_printf(
		 "\tIs virtual (FILE_ATTRIBUTE_VIRTUAL)\n" );
	}
}

/* Prints a log structure 
 * Returns 1 if successful or -1 on error
 */
int libesedb_debug_print_log_time(
     uint8_t *log_time,
     size_t log_time_size,
     const char *description,
     const char *indentation,
     liberror_error_t **error )
{
	static char *function = "libesedb_debug_print_log_time";

	if( log_time == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid log time.",
		 function );

		return( -1 );
	}
	if( log_time_size < 8 )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: log time too small.",
		 function );

		return( -1 );
	}
	if( log_time_size > (size_t) SSIZE_MAX )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid log time size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( description == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid description.",
		 function );

		return( -1 );
	}
	if( indentation == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid indentation.",
		 function );

		return( -1 );
	}
	libnotify_printf(
	 "%s: %s%s: %04d-%02d-%02d %02d:%02d:%02d (0x%02x 0x%02x)\n",
	 function,
	 description,
	 indentation,
	 1900 + log_time[ 5 ],
	 log_time[ 4 ],
	 log_time[ 3 ],
	 log_time[ 2 ],
	 log_time[ 1 ],
	 log_time[ 0 ],
	 log_time[ 6 ],
	 log_time[ 7 ] );

	return( 1 );
}

/* Prints the read offsets
 * Returns 1 if successful or -1 on error
 */
int libesedb_debug_print_read_offsets(
     libbfio_handle_t *file_io_handle,
     liberror_error_t **error )
{
	static char *function = "libesedb_debug_print_read_offsets";
	off64_t offset        = 0;
	size64_t size         = 0;
	int number_of_offsets = 0;
	int offset_iterator   = 0;

	if( file_io_handle == NULL )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file IO handle.",
		 function );

		return( -1 );
	}
	if( libbfio_handle_get_number_of_offsets_read(
	     file_io_handle,
	     &number_of_offsets,
	     error ) != 1 )
	{
		liberror_error_set(
		 error,
		 LIBERROR_ERROR_DOMAIN_RUNTIME,
		 LIBERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of offsets read.",
		 function );

		return( -1 );
	}
	libnotify_printf(
	 "Offsets read:\n" );

	for( offset_iterator = 0;
	     offset_iterator < number_of_offsets;
	     offset_iterator++ )
	{
		if( libbfio_handle_get_offset_read(
		     file_io_handle,
		     offset_iterator,
		     &offset,
		     &size,
		     error ) != 1 )
		{
			liberror_error_set(
			 error,
			 LIBERROR_ERROR_DOMAIN_RUNTIME,
			 LIBERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve offset: %d.",
			 function,
			 offset_iterator );

			return( -1 );
		}
		libnotify_printf(
		 "%08" PRIi64 " ( 0x%08" PRIx64 " ) - %08" PRIi64 " ( 0x%08" PRIx64 " ) size: %" PRIi64 "\n",
		 offset,
		 offset,
		 offset + (off64_t) size,
		 offset + (off64_t) size,
		 size );
	}
	libnotify_printf(
	 "\n" );

	return( 1 );
}

#endif

