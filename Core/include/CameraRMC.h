#pragma once
#include "MoveRMC.h"

// Camera Model Component

namespace Ion
{
	namespace Core
	{
		class Canvas;
		class TransformMC;

		class CameraRMC final
			: public Core::MoveRMC
		{
		public:
			explicit CameraRMC(bool isActive, Core::Object* pObject);
			virtual ~CameraRMC();
			CameraRMC(const CameraRMC& other) = default;
			CameraRMC(CameraRMC&& other) noexcept = default;
			CameraRMC& operator=(const CameraRMC& other) = default;
			CameraRMC& operator=(CameraRMC&& other) noexcept = default;

			virtual void Initialize() override;
			virtual void Update(float delta) override;
			virtual void Switch() override;
			virtual const std::vector<std::pair<std::string, Core::Command*>>& GetCommands() const override;
			virtual const std::string& GetName() const override;

			void SetCanvas(Core::Canvas* pCanvas);
			const DirectX::XMFLOAT4X4& GetView() const;
			const DirectX::XMFLOAT4X4& GetViewProjection() const;

			virtual void MoveForward(long long value) override;
			virtual void MoveBack(long long value) override;
			virtual void MoveLeft(long long value) override;
			virtual void MoveRight(long long value) override;
			virtual void MoveUp(long long value) override;
			virtual void MoveDown(long long value) override;
			virtual void RotateLeft(long long value) override;
			virtual void RotateRight(long long value) override;
		private:
			static const std::string mName;
			std::vector<std::pair<std::string, Core::Command*>> mCommands;

			Core::Canvas* mpCanvas;
			float
				mFarPlane,
				mNearPlane,
				mFOV;
			DirectX::XMFLOAT4X4 mView;
			DirectX::XMFLOAT4X4 mViewProjection;
			Core::TransformMC* mpTransform;
			// My best guess is that boolean operations are thread-safe
			// Implement std::atomic if needed
			bool
				mMoveForward[2],
				mMoveBack[2],
				mMoveLeft[2],
				mMoveRight[2],
				mMoveUp[2],
				mMoveDown[2],
				mRotateLeft[2],
				mRotateRight[2];
		};
	}
}
