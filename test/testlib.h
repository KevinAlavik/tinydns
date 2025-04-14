/***************************************************************************
 *
 * Copyright (C) Kevin Alavik <kevin@alavik.se>, and contributors
 *
 * This software is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef TINYDNS_TESTLIB_H
#define TINYDNS_TESTLIB_H

#include <stdio.h>
#include <stdlib.h>

/* Exit codes for Automake test integration */
#define TEST_PASS     0
#define TEST_FAIL     1
#define TEST_SKIP     77
#define TEST_ERROR    99

/* Internal helper to stringify expressions */
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

/* Enhanced macros with detailed output */
#define SKIP_IF(cond, msg) \
    do { \
        if (cond) { \
            fprintf(stderr, "SKIP at %s:%d: %s, Reason: %s\n", __FILE__, __LINE__, STR(cond), msg); \
            return TEST_SKIP; \
        } \
    } while (0)

#define FAIL_IF(cond, msg) \
    do { \
        if (cond) { \
            fprintf(stderr, "FAIL at %s:%d: %s, Reason: %s\n", __FILE__, __LINE__, STR(cond), msg); \
            return TEST_FAIL; \
        } \
    } while (0)

#endif /* TINYDNS_TESTLIB_H */
