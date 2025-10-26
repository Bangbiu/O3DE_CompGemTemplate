
#include <CustomGemComponent.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

namespace CustomGem
{
    //AZ_COMPONENT_IMPL(CustomGemComponent, "CustomGemComponent", "{84F70987-84AC-4670-9F3D-16640ED10BBE}");

    void CustomGemComponent::Activate()
    {
        CustomGemComponentRequestBus::Handler::BusConnect(GetEntityId());
    }

    void CustomGemComponent::Deactivate()
    {
        CustomGemComponentRequestBus::Handler::BusDisconnect(GetEntityId());
    }

    void CustomGemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<CustomGemComponent, AZ::Component>()
                ->Version(1)
                ;

            if (AZ::EditContext* editContext = serializeContext->GetEditContext())
            {
                editContext->Class<CustomGemComponent>("CustomGemComponent", "[Description of functionality provided by this component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "ComponentCategory")
                    ->Attribute(AZ::Edit::Attributes::Icon, "Icons/Components/Component_Placeholder.svg")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC_CE("Game"))
                    ;
            }
        }

        if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
        {
            behaviorContext->Class<CustomGemComponent>("CustomGem Component Group")
                ->Attribute(AZ::Script::Attributes::Category, "CustomGem Gem Group")
                ;
        }
    }

    void CustomGemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("CustomGemComponentService"));
    }

    void CustomGemComponent::GetIncompatibleServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
    }

    void CustomGemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void CustomGemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
} // namespace CustomGem
