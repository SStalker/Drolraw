// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ResourceIdentifiers.h"
#include <map>
/**
 *
 */
class DROLRAW_API Order
{
	typedef void(*voidfuncptr)(int,CharacterCard*);
	std::map<int, voidfuncptr> voida;

public:
	void insert(int id, voidfuncptr ptr){
			voida[id] = ptr;
	}

	voidfuncptr getOrder(int id);
};
