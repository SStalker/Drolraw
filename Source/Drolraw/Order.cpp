// Fill out your copyright notice in the Description page of Project Settings.

#include "Drolraw.h"
#include "Order.h"

Order::voidfuncptr Order::getOrder(int id)
{
    return voida.at(id);
}
