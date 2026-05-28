from pgmpy.models import BayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

model = BayesianNetwork([
    ("Rain", "Traffic"),
    ("Traffic", "Late")
])

cpd_rain = TabularCPD(
    variable="Rain",
    variable_card=2,
    values=[[0.7], [0.3]]
)

cpd_traffic = TabularCPD(
    variable="Traffic",
    variable_card=2,
    values=[
        [0.8, 0.3],
        [0.2, 0.7]
    ],
    evidence=["Rain"],
    evidence_card=[2]
)

cpd_late = TabularCPD(
    variable="Late",
    variable_card=2,
    values=[
        [0.9, 0.4],
        [0.1, 0.6]
    ],
    evidence=["Traffic"],
    evidence_card=[2]
)

model.add_cpds(cpd_rain, cpd_traffic, cpd_late)

inference = VariableElimination(model)

result = inference.query(
    variables=["Late"],
    evidence={"Rain": 1}
)

print(result)
