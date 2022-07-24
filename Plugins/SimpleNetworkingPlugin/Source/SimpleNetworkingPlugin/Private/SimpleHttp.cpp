// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleHttp.h"

// Sets default values
ASimpleHttp::ASimpleHttp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Http = &FHttpModule::Get();

}

// Called when the game starts or when spawned
void ASimpleHttp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleHttp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASimpleHttp::GetRequest(FString URL)
{
    TSharedRef<IHttpRequest> Request = Http->CreateRequest();

    Request->SetURL(URL);
    Request->SetVerb("GET");

    Request->OnProcessRequestComplete().BindLambda([&](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) mutable
    {
        bool success = bWasSuccessful && Response->GetResponseCode() >= 200 && Response->GetResponseCode() < 300;
        FString string = success ? Response->GetContentAsString() : "";
        GetRequestDispather.Broadcast(success, string);

        //UE_LOG(LogTemp, Log, TEXT("%s"), *string)
    });

    Request->ProcessRequest();
}

void ASimpleHttp::PostRequest(FString URL, FString JsonString)
{
    TSharedRef<IHttpRequest> Request = Http->CreateRequest();
    Request->SetURL(URL);
    Request->SetVerb("POST");
    Request->SetHeader("Content-Type", TEXT("application/json"));
    Request->SetContentAsString(JsonString);
    Request->ProcessRequest();
}
