/*
** Copyright 2014-2018 The Earlham Institute
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
/*
 * row_phenotype.h
 *
 *  Created on: 11 Sep 2018
 *      Author: billy
 */

#ifndef SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_ROW_PHENOTYPE_H_
#define SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_ROW_PHENOTYPE_H_


#include "typedefs.h"
#include "phenotype.h"
#include "row.h"


typedef struct RowPhenotype
{
	uint32 rp_id;

	Phenotype *rp_phenotype_p;

	bool rp_corrected_flag;

	char *rp_method_s;

	Row *rp_row_p;

} RowPhenotype;



#endif /* SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_ROW_PHENOTYPE_H_ */