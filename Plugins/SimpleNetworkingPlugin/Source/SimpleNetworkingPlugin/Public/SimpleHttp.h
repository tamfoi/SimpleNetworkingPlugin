// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "SimpleHttp.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGetRequestDispather, bool, bSuccess, FString, JsonString);

UCLASS()
class SIMPLENETWORKINGPLUGIN_API ASimpleHttp : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASimpleHttp();

	FHttpModule* Http;

	UFUNCTION(BlueprintCallable, Category = "SimpleNetworkingPlugin")
	void GetRequest(FString URL);

	UPROPERTY(BlueprintAssignable, Category = "SimpleNetworkingPlugin")
	FGetRequestDispather GetRequestDispather;

	UFUNCTION(BlueprintCallable, Category = "SimpleNetworkingPlugin")
	void PostRequest(FString URL, FString JsonString);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
