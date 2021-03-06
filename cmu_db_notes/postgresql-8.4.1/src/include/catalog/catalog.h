/*-------------------------------------------------------------------------
 *
 * catalog.h
 *	  prototypes for functions in backend/catalog/catalog.c
 *
 *
 * Portions Copyright (c) 1996-2009, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/catalog/catalog.h,v 1.44 2009/06/11 14:49:09 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef CATALOG_H
#define CATALOG_H // 系统表操作，包含用于操作系统表的专用函数

#include "catalog/pg_class.h"
#include "storage/relfilenode.h"
#include "utils/relcache.h"


extern const char *forkNames[];
extern ForkNumber forkname_to_number(char *forkName);

extern char *relpath(RelFileNode rnode, ForkNumber forknum);
extern char *GetDatabasePath(Oid dbNode, Oid spcNode);

extern bool IsSystemRelation(Relation relation);
extern bool IsToastRelation(Relation relation);

extern bool IsSystemClass(Form_pg_class reltuple);
extern bool IsToastClass(Form_pg_class reltuple);

extern bool IsSystemNamespace(Oid namespaceId);
extern bool IsToastNamespace(Oid namespaceId);

extern bool IsReservedName(const char *name);

extern bool IsSharedRelation(Oid relationId);

extern Oid	GetNewOid(Relation relation);
extern Oid GetNewOidWithIndex(Relation relation, Oid indexId,
				   AttrNumber oidcolumn);
extern Oid GetNewRelFileNode(Oid reltablespace, bool relisshared,
				  Relation pg_class);

#endif   /* CATALOG_H */
