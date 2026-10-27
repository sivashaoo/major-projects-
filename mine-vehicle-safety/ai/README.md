# MineGuard AI Module

## Goal

Detect and classify relevant objects from thermal imagery in low-visibility conditions.

## Classes

- Truck
- Person
- Rock
- Unknown

## Training Workflow

```text
Thermal Data Collection
        ↓
Image Cleaning / Labelling
        ↓
Train / Validation / Test Split
        ↓
Model Training
        ↓
Accuracy + Precision + Recall Evaluation
        ↓
Edge Optimization
        ↓
Real-time Inference
        ↓
Risk Engine
```

## Edge Impulse Direction

Edge Impulse can be used for the initial dataset, training and embedded inference workflow.

## Safety Integration

AI confidence is only one input to the safety decision. A low-confidence or missing detection should not automatically be treated as a clear road. The system should combine AI output with distance sensing, object motion, visibility and sensor-health information.

## Dataset Requirements

The dataset should contain representative examples of:

- Dense and light fog.
- Dust and rain.
- Different truck orientations.
- People at different distances.
- Rocks and road obstacles.
- Hot and cool backgrounds.
- Partial occlusion.
- Camera contamination.

## Evaluation Metrics

Record at minimum:

- Precision.
- Recall.
- F1 score.
- False-positive rate.
- False-negative rate.
- Detection latency.
- Performance by visibility condition.

## Important Limitation

The AI model is a prototype component. A production safety function requires a much larger representative dataset, rigorous validation and an appropriate safety-engineering process.
