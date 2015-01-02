/*
 * arcus-memcached - Arcus memory cache server
 * Copyright 2015 JaM2in Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _ARCUS_H_
#define _ARCUS_H_

#include "config.h"
#include "memcached/extension_loggers.h"

#ifdef ENABLE_ZK_INTEGRATION

/* Interface between memcached.c and arcus_zk.c */

extern volatile sig_atomic_t arcus_zk_shutdown;

void arcus_zk_init(char *ensemble_list, int zk_to,
                   EXTENSION_LOGGER_DESCRIPTOR *logger,
                   int verbose, size_t maxbytes, int port);
void arcus_zk_final(const char *msg);

int  arcus_zk_set_ensemble(char *ensemble_list);
int  arcus_zk_get_ensemble_str(char *buf, int size);
int  arcus_zk_get_timeout(void);

#ifdef ENABLE_CLUSTER_AWARE
bool arcus_cluster_is_valid(void);
bool arcus_key_is_mine(const char *key, size_t nkey);
#endif

#endif /* ENABLE_ZK_INTEGRATION */

#endif /* !defined(_ARCUS_H_) */
