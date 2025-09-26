#ifndef FALLOUT_INT_EXPORT_H_
#define FALLOUT_INT_EXPORT_H_

#include "intrpret.h"

//namespace fallout {

int exportStoreVariable(Program* program, const char* identifier, ProgramValue& value);
int exportFetchVariable(Program* program, const char* name, ProgramValue& value);
int exportExportVariable(Program* program, const char* identifier);
void initExport();
void exportClose();
Program* exportFindProcedure(const char* identifier, int* addressPtr, int* argumentCountPtr);
int exportExportProcedure(Program* program, const char* identifier, int address, int argumentCount);
void exportClearAllVariables();

//}

#endif /* FALLOUT_INT_EXPORT_H_ */
