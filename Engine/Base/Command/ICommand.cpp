#include "ICommand.h"
#include "../DescriptorHeaps/SRV.h"

void ICommand::Init(ID3D12Device* device, DXC* dxc, ID3D12RootSignature* signature, ID3D12Resource* resource, std::wstring vs, std::wstring ps, int32_t blendType)
{
	// PSOの生成
	CreatePSO(device, dxc, signature, vs, ps, blendType);

	// インデックスバッファの生成
	std::unique_ptr<IndexBuffer> newIndexBuffer = std::make_unique<IndexBuffer>(); // インスタンス生成
	newIndexBuffer->resource = resource; // インデックス情報を代入
	newIndexBuffer->resource->Map(0, nullptr, reinterpret_cast<void**>(&newIndexBuffer->indexData)); // マッピング

	// 生成するビューの設定
	D3D12_SHADER_RESOURCE_VIEW_DESC indexDesc{};
	indexDesc.Format = DXGI_FORMAT_UNKNOWN;										  // フォーマット形式は不明
	indexDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING; // シェーダーからテクスチャにアクセスする際の値指定
	indexDesc.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;						  // これはバッファであることを指定
	indexDesc.Buffer.FirstElement = 0;											  // ビューからアクセスする最初のアドレスを指定
	indexDesc.Buffer.Flags = D3D12_BUFFER_SRV_FLAG_NONE;						  // デフォルトのビューに表示
	indexDesc.Buffer.NumElements = kMaxIndex;									  // インデックス情報の最大数指定
	indexDesc.Buffer.StructureByteStride = sizeof(IndexInfoStruct);				  // バッファサイズを構造体1つ分に設定
	// srvヒープの未使用ハンドルを取得、インデックスバッファに代入
	newIndexBuffer->view = srv_->GetGPUHandle(srv_->GetUsedCount());
	// 設定を基にヒープの未使用ハンドルにビューの生成
	device->CreateShaderResourceView(newIndexBuffer->resource.Get(), &indexDesc, srv_->GetCPUHandle(srv_->GetUsedCount()));

	// バッファに追加
	indexBuffer_ = (std::move(newIndexBuffer));

	// srvヒープ使用数をインクリメント
	srv_->AddUsedCount();
}

void ICommand::SetDescriptorHeap(RTV* rtv, SRV* srv, DSV* dsv)
{
	// メンバ変数にヒープ本体を代入
	rtv_ = rtv; // レンダーターゲットビュー
	srv_ = srv; // シェーダーリソースビュー
	dsv_ = dsv; // 深度ステンシルビュー
}

void ICommand::CreatePSO(ID3D12Device* device, DXC* dxc, ID3D12RootSignature* signature, std::wstring vs, std::wstring ps, int32_t blendType, UINT wire)
{
	// 基底クラスでは記述を行わない
	// 以下は警告回避の参照
	device;
	dxc;
	signature;
	vs;
	ps;
	blendType;
	wire;
}

D3D12_RESOURCE_BARRIER ICommand::SettingResourceBarrier(ID3D12Resource* resource, D3D12_RESOURCE_STATES stateBefore, D3D12_RESOURCE_STATES stateAfter)
{
	// TransitionBarrierの設定を行う
	D3D12_RESOURCE_BARRIER barrier{};
	barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION; // TransitionBarrier
	barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;	   // None
	barrier.Transition.pResource = resource;			   // 設定を行うバッファ
	barrier.Transition.StateBefore = stateBefore;		   // 現在のフロントバッファ
	barrier.Transition.StateAfter = stateAfter;			   // 現在のバックバッファ

	// 設定を返す
	return barrier;
}
