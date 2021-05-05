/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma once

#include <coin.h>
#include <zxtypes.h>
#include <zxerror.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t pubkeytype;
    uint32_t lenDependencies;
    uint32_t lenChainName;
} parser_header_t;

#define NUM_RUNTIME_TYPES 21

#define NUM_DEPLOY_TYPES 6
typedef enum {
    ModuleBytes = 0,
    StoredContractByHash = 1,
    StoredContractByName = 2,
    StoredVersionedContractByHash = 3,
    StoredVersionedContractByName = 4,
    Transfer = 5,
} deploy_type_e;


typedef struct {
    deploy_type_e type;
    uint32_t num_items;
    uint32_t totalLength;
} ExecutableDeployItem;

typedef struct {
    parser_header_t header;
    ExecutableDeployItem payment;
    ExecutableDeployItem session;
} parser_tx_t;

//let payment_args = runtime_args! {
//"quantity" => 1000
//};
//let payment = ExecutableDeployItem::StoredContractByName {
//        name: String::from("casper-example"),
//        entry_point: String::from("example-entry-point"),
//        args: payment_args,
//};
#ifdef __cplusplus
}
#endif