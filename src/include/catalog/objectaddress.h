/*-------------------------------------------------------------------------
 *
 * objectaddress.h
 *	  functions for working with object addresses
 *
 * Portions Copyright (c) 1996-2013, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/objectaddress.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef OBJECTADDRESS_H
#define OBJECTADDRESS_H

#include "nodes/pg_list.h"
#include "storage/lock.h"
#include "utils/acl.h"
#include "utils/relcache.h"

/*
 * An ObjectAddress represents a database object of any type.
 */
typedef struct ObjectAddress
{
	Oid			classId;		/* Class Id from pg_class */
	Oid			objectId;		/* OID of the object */
	int32		objectSubId;	/* Subitem within object (eg column), or 0 */
} ObjectAddress;

extern ObjectAddress get_object_address(ObjectType objtype, List *objname,
				   List *objargs, Relation *relp,
				   LOCKMODE lockmode, bool missing_ok);

extern void check_object_ownership(Oid roleid,
					   ObjectType objtype, ObjectAddress address,
					   List *objname, List *objargs, Relation relation);

extern Oid	get_object_namespace(const ObjectAddress *address);

extern Oid				get_object_oid_index(Oid class_id);
extern int				get_object_catcache_oid(Oid class_id);
extern int				get_object_catcache_name(Oid class_id);
extern AttrNumber		get_object_attnum_name(Oid class_id);
extern AttrNumber		get_object_attnum_namespace(Oid class_id);
extern AttrNumber		get_object_attnum_owner(Oid class_id);
extern AttrNumber		get_object_attnum_acl(Oid class_id);
extern AclObjectKind	get_object_aclkind(Oid class_id);

#endif   /* PARSE_OBJECT_H */